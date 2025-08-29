# minitalk

Welcome to **minitalk**!  
A simple and amazing project for message communication between processes using UNIX signals.

## 📖 Overview

minitalk is a lightweight educational project demonstrating inter-process communication (IPC) in C using signals. It consists of a server and a client program. The client sends messages to the server, which receives and displays them.

## 🚀 Features

- Send messages from client to server using UNIX signals
- Handles string messages character by character
- Robust error handling for invalid PIDs and signals
- Simple CLI interface for both server and client
- Clean, readable code for learning IPC concepts

## 🧰 Prerequisites

- GCC or compatible C compiler
- Make utility
- UNIX-like operating system (Linux, macOS, WSL, etc.)

## 📦 Installation

Clone the repository:
```bash
git clone https://github.com/yourusername/minitalk.git
cd minitalk
```

Build the project:
```bash
make
```

## 🛠️ Usage

### Start the server

Run the server and note its PID:
```bash
./server
```
The server will print its PID. You need this for the client.

### Send a message from the client

Open another terminal and run:
```bash
./client <server_pid> "Your message here"
```
Replace `<server_pid>` with the actual PID printed by the server.

#### Example

```bash
./client 12345 "Hello, minitalk!"
```

### Expected Output

The server will display:
```
Received message: Hello, minitalk!
```

## 🧑‍💻 Troubleshooting

- **Server not receiving messages:** Ensure you are using the correct PID and both programs are running on the same machine.
- **Permission denied:** Make sure both executables have execute permissions (`chmod +x server client`).
- **Compilation errors:** Check your compiler version and that all dependencies are installed.

## 🤝 Contributing

Pull requests are welcome!  
For major changes, please open an issue first to discuss what you would like to change.

## 📄 License

This project is licensed under the MIT License.

## 📬 Contact

For questions or feedback, open an issue on GitHub or email `your.email@example.com`.

---

Enjoy messaging with minitalk! 🚀

# Happy Coding!
