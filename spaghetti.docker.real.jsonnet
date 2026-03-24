{
  plugs: {
    serial: std.format("ws://host.docker.internal:9600/open?port=%s&baudrate=115200", [
      std.extVar("COM_PORT"),
    ]),
    gaia: "ws://localhost:8910",
    eb90dec: "exec:kble-eb90 decode",
    eb90enc: "exec:kble-eb90 encode",
    to_aos_tf: "exec:kble-c2a spacepacket to-aos-tf",
    from_tc_tf: "exec:kble-c2a spacepacket from-tc-tf",
  },
  links: {
    gaia: "from_tc_tf",
    from_tc_tf: "eb90enc",
    eb90enc: "serial",

    serial: "eb90dec",
    eb90dec: "to_aos_tf",
    to_aos_tf: "gaia",
  }
}
