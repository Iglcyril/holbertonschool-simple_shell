# simple shell project

![alt text](

## Simple Shell

A lightweight UNIX command line interpreter written in C that mimics the basic functionality. This project demonstrates fundamental concepts of process creation, system calls, and command parsing.

## Overview

This shell provides a simple command-line interface where users can execute commands, navigate directories, and interact with the operating system. It handles both built-in commands and external programs found in the system PATH.

## Requirements 



##  Files description

File | Description | 
----------|-------------|
strip_newline.c | program that removes the trailing newline character from a string.
executor.c | program that execute a command using fork and execve.
free_array.c | program that frees a NULL-terminated array of strings
get_env_value.c | program that returns the value of an environment variable
clean_quote.c | program that removes surrounding quotes from a token if present.
token_count | program Count tokens in a string

## Function we use

```c

```
## flowchart


## Compilation
``` 
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```