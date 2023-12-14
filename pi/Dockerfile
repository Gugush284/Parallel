FROM library/gcc:13.2.0

WORKDIR /build

RUN apt-get update
RUN apt-get install -y curl cmake

COPY src /build/source/src
COPY CMakeLists.txt /build/source/CMakeLists.txt
RUN mkdir /build/bin

WORKDIR /build/bin

RUN cmake /build/source
RUN make
RUN main