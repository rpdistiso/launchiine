FROM devkitpro/devkitppc:20241116

# Install required packages for building bin2s
RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    git \
    build-essential \
    cmake \
    gcc \
    g++ \
    libargs-dev

# Clone and build bin2s
RUN git clone https://github.com/Xtansia/bin2s.git /tmp/bin2s && \
    cd /tmp/bin2s && \
    cmake . && \
    make && \
    make install && \
    rm -rf /tmp/bin2s && \
    which bin2s

WORKDIR project