#!/usr/bin/env python3
import argparse
import asyncio
import logging
from typing import Optional

import serial
from serial import serialposix
from serial import serialutil
import serial_asyncio
import uvicorn
from fastapi import FastAPI, WebSocket, WebSocketDisconnect

for name in (
    "FIVEBITS",
    "SIXBITS",
    "SEVENBITS",
    "EIGHTBITS",
    "PARITY_NONE",
    "PARITY_EVEN",
    "PARITY_ODD",
    "PARITY_MARK",
    "PARITY_SPACE",
    "STOPBITS_ONE",
    "STOPBITS_ONE_POINT_FIVE",
    "STOPBITS_TWO",
):
    if hasattr(serialutil, name) and not hasattr(serial, name):
        setattr(serial, name, getattr(serialutil, name))

if not hasattr(serial, "SerialException"):
    serial.SerialException = serialutil.SerialException
if not hasattr(serial, "SerialTimeoutException"):
    serial.SerialTimeoutException = serialutil.SerialTimeoutException
if not hasattr(serial, "Serial"):
    serial.Serial = serialposix.Serial
if not hasattr(serial, "serial_for_url"):
    def serial_for_url(url=None, *args, **kwargs):
        if url is None:
            url = kwargs.pop("port", None)
        if url is None:
            raise ValueError("missing serial port URL")
        return serialposix.Serial(port=url, *args, **kwargs)

    serial.serial_for_url = serial_for_url

app = FastAPI()


def parse_databits(value: Optional[str]) -> int:
    if value is None:
        return serialutil.EIGHTBITS
    mapping = {
        "5": serialutil.FIVEBITS,
        "6": serialutil.SIXBITS,
        "7": serialutil.SEVENBITS,
        "8": serialutil.EIGHTBITS,
    }
    if value not in mapping:
        raise ValueError(f"invalid databits: {value}")
    return mapping[value]


def parse_flowcontrol(value: Optional[str]):
    if value is None:
        return False, False
    value = value.lower()
    if value == "none":
        return False, False
    if value == "software":
        return True, False
    if value == "hardware":
        return False, True
    raise ValueError(f"invalid flowcontrol: {value}")


def parse_parity(value: Optional[str]) -> str:
    if value is None:
        return serialutil.PARITY_NONE
    mapping = {
        "none": serialutil.PARITY_NONE,
        "even": serialutil.PARITY_EVEN,
        "odd": serialutil.PARITY_ODD,
    }
    value = value.lower()
    if value not in mapping:
        raise ValueError(f"invalid parity: {value}")
    return mapping[value]


def parse_stopbits(value: Optional[str]):
    if value is None:
        return serialutil.STOPBITS_ONE
    mapping = {
        "1": serialutil.STOPBITS_ONE,
        "2": serialutil.STOPBITS_TWO,
    }
    if value not in mapping:
        raise ValueError(f"invalid stopbits: {value}")
    return mapping[value]


@app.websocket("/open")
async def open_serial(websocket: WebSocket):
    await websocket.accept()

    params = websocket.query_params

    try:
        port = params["port"]
        baudrate = int(params["baudrate"])
        databits = parse_databits(params.get("databits"))
        parity = parse_parity(params.get("parity"))
        stopbits = parse_stopbits(params.get("stopbits"))
        xonxoff, rtscts = parse_flowcontrol(params.get("flowcontrol"))

        reader, writer = await serial_asyncio.open_serial_connection(
            url=port,
            baudrate=baudrate,
            bytesize=databits,
            parity=parity,
            stopbits=stopbits,
            xonxoff=xonxoff,
            rtscts=rtscts,
        )
    except Exception as exc:
        logging.exception("failed to open serial port")
        await websocket.close(code=1011, reason=str(exc))
        return

    async def serial_to_ws():
        try:
            while True:
                data = await reader.read(4096)
                if not data:
                    break
                await websocket.send_bytes(data)
        except Exception:
            logging.exception("serial_to_ws error")
        finally:
            raise asyncio.CancelledError

    async def ws_to_serial():
        try:
            while True:
                message = await websocket.receive()

                if message["type"] == "websocket.disconnect":
                    break

                data = message.get("bytes")
                text = message.get("text")

                if data is not None:
                    writer.write(data)
                    await writer.drain()
                elif text is not None:
                    writer.write(text.encode())
                    await writer.drain()
        except WebSocketDisconnect:
            pass
        except Exception:
            logging.exception("ws_to_serial error")
        finally:
            raise asyncio.CancelledError

    task1 = asyncio.create_task(serial_to_ws())
    task2 = asyncio.create_task(ws_to_serial())

    _, pending = await asyncio.wait(
        [task1, task2],
        return_when=asyncio.FIRST_COMPLETED,
    )

    for task in pending:
        task.cancel()

    writer.close()
    try:
        await writer.wait_closed()
    except Exception:
        pass

    try:
        await websocket.close()
    except Exception:
        pass


def main():
    parser = argparse.ArgumentParser(
        description="WebSocket <-> Serial bridge server"
    )
    parser.add_argument("--addr", default="0.0.0.0")
    parser.add_argument("--port", type=int, default=9600)
    parser.add_argument("--log-level", default="info")
    args = parser.parse_args()

    logging.basicConfig(
        level=getattr(logging, args.log_level.upper(), logging.INFO),
        format="%(asctime)s %(levelname)s %(message)s",
    )

    uvicorn.run(app, host=args.addr, port=args.port, log_level=args.log_level)


if __name__ == "__main__":
    main()
