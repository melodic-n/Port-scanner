# 🔍 Port Scanner in C

A simple command-line port scanner written in C for educational and cybersecurity practice purposes. It allows you to scan a specific port or all common ports on a target IP address to identify open services.

\
This project was made in a Linux environement.

## 🚀 Features

- Scan a specific port on a given IP address
- Detect OS running on the target machine
- Scan all well-known ports (1–1023)
- Simple terminal interface

## 🧪 Usage

When you run the scanner, you'll be prompted to enter an IP address and select a scan mode:

Insert Server's IP Address (to test, use 127.0.0.1 or 0.0.0.0)\
1 - Scan all open ports \
2 - Scan a specific port


Compile the scanner using:

```bash
gcc portscanner.c -o portscanner
./portscanner
```
🐳 Docker for Testing

To test the scanner safely in a local environment, you can spin up a test container with SSH and Apache running.
🧱 Build the Docker image:
```
docker build -t ssh-apache .
```

🚀 Run the container:
```
docker run -dit -p 8080:80 -p 2222:22 --name multiservice ssh-apache
```
 This starts a container with SSH and Apache services exposed.

 You can scan 127.0.0.1 on port 8080 (Apache) or 2222 (SSH).

    Feel free to install more services inside the container for testing.

You can modify this Dockerfile to run services in the foreground or use a process manager like supervisord if needed.

⚠️ Disclaimer

This tool is intended for educational purposes only. Do not scan networks or systems without permission.
