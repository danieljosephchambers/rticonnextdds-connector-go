FROM --platform=linux/amd64 ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential

WORKDIR /src

# Copy source files and RTI dependencies
COPY helper/ ./helper/
COPY include/rticonnextdds-connector.h ./include/
COPY rticonnextdds-connector/include/ ./include/
COPY rticonnextdds-connector/lib/linux-x64/ ./lib/

# Build shared library
RUN gcc -fPIC -shared \
    -Ihelper \
    -Iinclude \
    -Iinclude/lua_binding \
    -Llib \
    -lrtiddsconnector \
    -o libguid_helper.so helper/guid_helper.c

# Copy the output
RUN mkdir /output
RUN cp libguid_helper.so /output/

CMD ["sleep", "infinity"]
