FROM rust:1.86-bookworm

RUN apt-get update && apt-get install -y --no-install-recommends \
    curl \
    build-essential \
    gcc-multilib \
    protobuf-compiler \
    libclang-dev \
    cmake \
    g++ \
    g++-multilib \
    python3 \
    python3-pip \
    git \
    dos2unix \
    ca-certificates \
    nodejs \
    npm \
    && rm -rf /var/lib/apt/lists/*

RUN npm install -g pnpm@9.1.1

ENV PATH="/root/.cargo/bin:${PATH}"

WORKDIR /root/c2a-aobc-core-v4
COPY . .

RUN dos2unix /root/c2a-aobc-core-v4/boom-tools/install.sh
RUN pnpm install
RUN rustup target add i686-unknown-linux-gnu

CMD ["bash"]
