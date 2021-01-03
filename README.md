# TCP Files storage server

This is an implementation of a CPP server over tcp with boost

## Server

The server is developed using C++ with Boost.

Server was tested over ubuntu over x64.
Tested with Boost version 1.75.0.

### Compiling the server

#### Using Make

For easy compilation a makefile support had been added.
You should update the BOOST libraries and include files location before the compilation.
 
#### Using Docker

To make it even easier a Dockerfile is included.

To build using docker:

``` Docker build -t tcp-server . ```

To run it:

``` Docker run -it tcp-server ```

## Client

A sample client is included.
The client is using python 3.x

To run it go to the "client" folder and run with python3 the file "client_main.py"
