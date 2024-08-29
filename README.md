# File Copy Programs

This repository contains two C programs designed to copy the contents of one file to another. One program is for Unix-like systems (such as Linux), and the other is for Windows.

## Overview

Both programs perform the same functionality:
- Open an input file for reading.
- Open (or create) an output file for writing.
- Copy the contents from the input file to the output file using a buffer.

## Usage

To use these programs, compile them according to your operating system and run with the appropriate command-line arguments.

### Unix-Based Program

The Unix-based program uses low-level system calls (`open`, `read`, `write`, `close`) to handle file operations.

#### Compilation

```bash
gcc -o file_copy_unix file_copy_unix.c
