# Descripton

This project is compiled for x86_64 Linux platform ubuntu. So contact me if this project isn't work for your environment.
In this project I getting some values from a smart meter, preparing a message for the server with the values from meter and sending it to a server. Please refer to "Requirements" section of this document for details.

I develop a tcp server project to listen client and see packages. Please download the server project given below link.
https://github.com/ahmetermankose/tcp_server

Server side must be your local machine. So you can listen for port(8080) and your application run on the same machine.


## How to Build Project

Please use the given gcc command :
gcc main.c obisManager.c cJSON.c cJSON_Utils.c jsonParser.c aesSecurity.c tcpClient.c -L/usr/local/include/ -L/usr/local/lib64 -lcrypto -L. -lmeter -o luna_program

## How to Run Project

Please use the given command :
./luna_program

## Output of The Project
![plot](./home/ahmet/Pictures/outputOfTCPClient.png)

## Preliminary Information

### TCP Communication and AES128 Details

Information in the smart meters are stored and read with OBIS codes, some kind of object numbers. Below you can find some (pseudo) OBIS codes. They are applicable for this assignment.

Title       | Description
---         | ---
Client IP   | 127.0.0.1
Server IP   | 127.0.0.1
Port        | 8080
AES TYPE    | CBC
IV          | 0000000000000000
AES Key     | 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF

## Requirements for this project
1. You have to get openssl libraries.
    - Get openssl libraries using given link.
    - https://www.openssl.org/source/
    - Download openssl
    - Unzip openssl folder
    - Enter the folder using terminal
    - ./config shared --prefix=/usr/local/
    - make
    - make install
    - NOTE: Change the location /usr/local/ and you must have root permissions (sudo)
2. Do not run the client project before run server project
  

