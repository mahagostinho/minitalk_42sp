# minitalk_42sp
<p align="center">
    <img src="https://user-images.githubusercontent.com/102881479/215282296-839ce5e6-5982-41f6-ba56-7e408f6ca9f8.png">
</p>
<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-blue.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

## Introduction

The purpose of this project is to code a small data exchange program using UNIX signals. Therefore, the communication program between a `client` and a `server` has to be done using only UNIX signals.

The `server` should be able to receive messages from clients in a row without needing to restart. For the bonus project, the `server` confirm the message was delivered by sending back a signal to the `client` and supports Unicode characters.

## How to compile and run the project

#### 1) Copy this repository to your local workstation using git clone

#### 2) Compile the project

```html
make
```

#### 3) Open two instances of the command terminal and, in one of them, launch the `server` program

```html
./server
```

It will print the server process ID:

```html
Server PID is: XXXX.
```
#### 4) In the other terminal, launch the `client` program

It must receive three arguments: the executable program, the server PID and the message to be sent.

```html
./client <PID> <MESSAGE>
```
To send another message to the `server`, the `client` program must be executed once again.
