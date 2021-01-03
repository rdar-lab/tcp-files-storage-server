from ishikocpp/gcc-boost
COPY * ./
RUN make

FROM alpine
COPY --from=0 /tcp-storage-server .
COPY ./port.info /
WORKDIR /
ENTRYPOINT ["./tcp-storage-server"]
