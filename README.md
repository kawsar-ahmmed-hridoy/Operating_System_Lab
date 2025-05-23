
# 💻 Operating System Lab

This repository contains a collection of practical assignments implemented in C, designed to reinforce theoretical concepts from an Operating Systems course. The exercises cover topics such as process management, thread creation, memory and file handling, CPU scheduling, synchronization, and shell scripting.

> ✅ Each subdirectory represents a separate topic with self-contained C programs.

---

## 🗂️ Directory Structure

```
Operating_System_Lab/
├── .vscode/                   # VS Code settings (optional)
├── Lab_Final/                 # Final exam lab questions and solutions
├── file_management/           # File operations like creation, deletion, and reading
├── process/                   # Process-related experiments (creation, termination, etc.)
├── process_synchronization/   # Classic synchronization problems (e.g., readers-writers)
├── scheduling/                # CPU scheduling algorithms like Priority Scheduling
├── shell_scripting/           # Shell script practices (arithmetic operations, logic)
├── thread/                    # Multithreading examples (creation, parameters, cancel/exit)
├── first.c                    # Initial C program with input/output logic
└── first                      # Executable for the first program
```

---

## 🔍 Key Topics Covered

### 📁 `file_management`

* File creation and manipulation
* Read/write using low-level I/O system calls

### 🧵 `thread`

* Thread creation and joining
* Passing arguments to threads
* Multithreading execution
* Thread cancellation and graceful termination

### 🧠 `process`

* Process creation using `fork()`
* Handling process termination

### 🔐 `process_synchronization`

* Readers-Writers problem
* Mutex usage and synchronization techniques

### 🧮 `scheduling`

* Preemptive priority scheduling
* CPU scheduling simulations

### 🐚 `shell_scripting`

* Basic scripting for arithmetic (sum, multiplication, division)
* Execution logic using shell

### 🧪 `Lab_Final`

* Solutions to final lab problems combining multiple OS topics

---

## 🚀 Getting Started

To compile and run any `.c` file:

```bash
gcc -o output_file source_file.c -pthread
./output_file
```

Example:

```bash
gcc -o multi_thread thread/multi_thread.c -pthread
./multi_thread
```

> Ensure you have a POSIX-compliant OS (e.g., Linux) and GCC installed.

---

## ✅ Requirements

* GCC compiler with pthread support
* Basic understanding of C and operating system fundamentals
* Linux or Unix-like terminal

---

## 🤝 Contributing

Feel free to fork the repository, open issues, and contribute via pull requests if you want to:

* Add new lab examples
* Improve code quality or logic
* Enhance documentation

---
