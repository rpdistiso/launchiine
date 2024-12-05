FROM devkitpro/devkitppc:latest

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

# Create build directory and generate headers
RUN mkdir -p project/build

# Generate headers from data files
COPY data data
RUN for file in $(find data -type f); do /opt/devkitpro/tools/bin/bin2s -a 32 "$file" -H "project/build/$(basename "$file" | tr . _).h"; done

WORKDIR project