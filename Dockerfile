FROM devkitpro/devkitppc:20241116

RUN git clone https://github.com/Xtansia/bin2s.git /tmp/bin2s && \
    cd /tmp/bin2s && \
    cmake . && \
    make && \
    make install && \
    rm -rf /tmp/bin2s

WORKDIR project
