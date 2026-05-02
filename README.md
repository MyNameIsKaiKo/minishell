> This project has been created as part of the 42 curriculum by jleray and nredouan.

# 🐚 Minishell by T&J

## 📋 Table of Contents

- [Description](#-description)
- [Features](#-features)
- [Builtins](#-builtins)
- [Requirements](#-requirements)
- [Instructions](#-instructions)
- [Authors](#-authors)
- [Resources](#-resources)
---

## 🧠 Description

**Minishell** is a 42 School project that involves recreating a simplified shell inspired by **Bash**. This project provides a deep understanding of how a Unix shell works: process management, signals, redirections, pipes, and much more.

---

## ✨ Features

- ✅ Display a custom **prompt** while waiting for a new command
- ✅ **Command history** (navigate with ↑ ↓ arrow keys)
- ✅ Search and launch executables via `$PATH` or relative/absolute paths
- ✅ **Single quotes** `'...'` — prevent interpretation of all metacharacters
- ✅ **Double quotes** `"..."` — prevent interpretation of metacharacters except `$`
- ✅ **Redirections**:
  - `<` — input redirection
  - `>` — output redirection
  - `>>` — output redirection in append mode
  - `<<` — here-document (reads until delimiter)
- ✅ **Pipes** `|` — connect the output of one command to the input of the next
- ✅ **Environment variables** (`$VAR`, `$?` for the last exit code, `$0` for the name of the executable)
- ✅ **Signal handling**: `Ctrl+C`, `Ctrl+D`, `Ctrl+\`

---

## 🔧 Builtins

The following commands are implemented natively:

| Command | Description |
|---------|-------------|
| `echo` | Print a message (`-n` to omit the trailing newline) |
| `cd` | Change the current working directory (no argument redirect in HOME value, `cd -` redirect in the last directory visited or `$OLDPWD`) |
| `pwd` | Print the current working directory |
| `export` | Set an environment variable (without arguments it display environment variable list) |
| `unset` | Unset an environment variable |
| `env` | Display all environment variables |
| `exit` | Exit the shell with a return code |

---

## 📦 Requirements

- `gcc` or `clang`
- `make`
- **readline** library (`libreadline-dev`)

```bash
# On Ubuntu/Debian
sudo apt-get install libreadline-dev
```

---

## 🚀 Instructions

```bash
# Clone the repository
git clone https://github.com/<your_login>/minishell.git
cd minishell

# Compile the project
make

# Launch the shell
./minishell
```

### Available Makefile commands

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and the binary
make re     # Recompile everything from scratch
```

---

## 👥 Authors

| Login | GitHub |
|-------|--------|
| `jleray` | [@MyNameIsKaiKo](https://github.com/MyNameIsKaiKo) |
| `nredouan` | [@nredouan](https://github.com/nredouan) |

---

## 📚 Resources

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [GNU Readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [Claude.ai](https://claude.ai/)
- [Gemini](https://gemini.google.com/)

### Note about AI
AI like Claude or Gemini were used only to learn how to use certain functions and fix issues when we were at an impasse.
