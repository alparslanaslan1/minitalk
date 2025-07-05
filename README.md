# Minitalk

**Minitalk** is a simple client-server communication program in C using UNIX signals (`SIGUSR1` and `SIGUSR2`). The client sends messages to the server, which prints them in real time.

## File Structure

```
minitalk/
├── client/
│   ├── client.c          # Client implementation: encodes and sends messages bit by bit
│   └── Makefile          # Build rules for client
├── server/
│   ├── server.c          # Server implementation: decodes signals into characters
│   └── Makefile          # Build rules for server
└── utils/
    ├── utils.c           # Shared helper functions (e.g., ft_itoa, ft_strlen)
    └── utils.h           # Prototypes and includes
```

## Compilation

1. **Build the server**:

   ```bash
   cd server
   make
   ```
2. **Build the client**:

   ```bash
   cd ../client
   make
   ```
3. **Clean build artifacts**:

   ```bash
   make clean       # Remove object files
   make fclean      # Remove objects and executables
   make re          # Full rebuild
   ```

## Usage

1. **Start the server** (prints its PID):

   ```bash
   ./server
   ```

2. **Send a message from the client**, using the server PID:

   ```bash
   ./client <SERVER_PID> "Your message here"
   ```

The server will display the message character by character as it receives signals.

## Author

* **Alparslan Aslan** ([alparslanaslan504@gmail.com](mailto:alparslanaslan504@gmail.com))

## License

No explicit license provided. Use, modify, and distribute at your own risk.
