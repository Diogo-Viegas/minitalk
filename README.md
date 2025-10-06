# 💻 Minitalk: Data Exchange with UNIX Signals

## Project from 42 Lisbon | Communication Program (Client/Server)

## Houston, we have a signal. 🚀

Minitalk is a fundamental project at 42 School that aims to code a small data exchange program using UNIX signals. This project strengthens knowledge of process communication, signal handling, and low-level system programming in C.

## 🎯 Overview

The Minitalk program is structured as two separate executables:a Client and a Server. 
Communication between the two processes is achieved exclusively using the SIGUSR1 and SIGUSR2 UNIX signals.
- Server: Must be started first and prints its Process ID (PID) upon launch.
- Client: Takes two parameters: the Server's PID and the string to send.

**Goal**: The client must send the specified string to the server, and the server must print it once received.

## ✨ Key Features

### Mandatory Part
**Signal-Based Communication:** Implements reliable one-way communication using only the SIGUSR1 and SIGUSR2 signals.

**Server Robustness:** The server is able to receive strings from several clients consecutively without needing to restart.

**Performance:** The server displays the received string without delay.

**Process Management:** Core experience in handling and managing processes, file descriptors, and system calls.

**Error Handling:** Thorough handling of arguments and system calls, preventing unexpected program termination (segmentation fault, bus error, double free, etc.).

### Bonus Features
**Signal Acknowledgement (Acknowledgement):**The server sends a signal to the client to confirm that the message has been successfully received.

**Unicode Support:** Capability to send and display Unicode characters.

### 🛠️ Installation and Usage

**1. Compilation**
The project requires a Makefile that compiles the source files to the required executables: client and server.
Compile the mandatory part (and libft, if used)
$ make

**2. Start the Server**
Execute the server first to obtain its PID.
$ ./server
Example Output:
$ Server PID: 7421

**3. Run the Client**
Use the PID displayed by the server to send a message.
Syntax: ./client [SERVER_PID] "MESSAGE"
`./client 7421 "Hello 42 Lisboa! This is Minitalk."`

### ⚙️ Constraints and Allowed Functions

**Language:** C

**Libraries:** Allowed to use your own libft library.

**Global Variables:** Allowed to use one global variable per program (client and server), but its usage must be justified.

**Memory:** Must be free of memory leaks, and all heap-allocated memory must be properly freed.

### Allowed Functions:
write, ft_printf (or equivalent), signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit.

write, ft_printf (or equivalent), signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit.

