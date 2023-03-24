# minitalk_42sp

## Introduction

The purpose of this project is to code a small data exchange program using UNIX signals. Therefore, the communication program between a `client` and a `server` has to be done using only UNIX signals.

The `server` should be able to receive messages from clients in a row without needing to restart. For the bonus project, the `server` confirm the message was delivered by sending back a signal to the `client` and supports Unicode characters.

## How to compile and run the project

### Copy this repository to your local workstation

```html
git clone https://github.com/mahagostinho/minitalk_42sp.git
```

### Compile the project

```html
make
```

### Open two instances of the command terminal and, in one of them, launch the `server` program

```html
./server
```

It will print the server process ID:

```html
Server PID is: XXXX.
```
### In the other terminal, launch the `client` program

It must receive three arguments: the executable program, the server PID and the message to be sent.

```html
./client <PID> <MESSAGE>
```
To send another message to the `server`, the `client` program must be executed once again.
