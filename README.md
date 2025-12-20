# simple shell project

<img width="1024" height="1024" alt="a9591cb3-202e-4931-9d88-8de9376b9fde" src="https://github.com/user-attachments/assets/979565b7-02fc-4f40-81c2-05534eb407ed" />


## Simple Shell

A lightweight UNIX command line interpreter written in C that mimics the basic functionality. This project demonstrates fundamental concepts of process creation, system calls, and command parsing.

## Overview

This shell provides a simple command-line interface where users can execute commands, navigate directories, and interact with the operating system. It handles both built-in commands and external programs found in the system PATH.

## Requirements 
```
Allowed editors: vi, vim, emacs

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

Your shell should not have any memory leaks

No more than 5 functions per file

All your header files should be include guarded

Use system calls only when you need to (why?)
```


##  Files description

File | Description | 
----------|-------------|
all_for_path.c | handles command search and execution for PATH.
builtin.c | Implementation shell commands.
clean_quote.c | program that removes surrounding quotes from a token if present.
executor.c | program that execute a command using fork and execve.
free_array.c | program that frees a NULL-terminated array of strings.
get_env_value.c | program that returns the value of an environment variable.
shell.h | file with all prototypes.
split_string.c | program to split string
strip_newline.c | program that removes the trailing newline character from a string.
token_count | program Count tokens in a string
 

## Function we use

All of this functions are in the shell.h file.
```c

char *build_path(char *dir_path, char *cmd_name);
int search_in_path(char **path_dirs, char **cmd_args, char **envp, char *prog_name);
int exec_direct(char **cmd_args, char **envp, char *prog_name);
int find_and_execute(char **cmd_args, char **envp, char *prog_name);

void builtin_env(char **envp);
void builtin_exit(int *exit_status, char *input_line);
int check_builtin(char **cmd_tokens, int *exit_status, char *input_line, char **envp);
	

char *clean_quotes(char *token);

int exec_cmd(char **argv, char **envp, char *prog_name);

void free_array(char **array);

char *get_env_value(const char *name, char **envp);

int main(int argc, char **argv, char **envp);

char **split_string(char *input_str, char *delim);

void strip_newline(char *input_str, ssize_t *str_len);

int token_count(const char *input_str, const char *delim);

```
## flowchart


## Man simple shell

![man_shell](https://github.com/Iglcyril/holbertonschool-simple_shell/blob/dev/man_shell)


## Compilation
``` 
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### Execute
```c
./hsh
```

## Test

In interactive mode
```
@Iglcyril ➜ /workspaces/holbertonschool-simple_shell (dev) $ ./hsh 
($) ls /var
backups  cache  lib  local  lock  log  mail  opt  run  spool  tmp  vscode-remote
($) echo holberton
holberton
($) exit
@Iglcyril ➜ /workspaces/holbertonschool-simple_shell (dev) $
```

In no interactive mode
```c
@Iglcyril ➜ /workspaces/holbertonschool-simple_shell (dev) $ ./hsh 
($) /bin/ls /var | hsh
/bin/ls: cannot access '|': No such file or directory
 hsh

/var:
backups  cache  lib  local  lock  log  mail  opt  run  spool  tmp  vscode-remote
($) exit
@Iglcyril ➜ /workspaces/holbertonschool-simple_shell (dev) $
```
## Valgrind test

```
==2226== 
==2226== Process terminating with default action of signal 2 (SIGINT)
==2226==    at 0x497CA91: read (read.c:26)
==2226==    by 0x48F37A4: _IO_file_underflow@@GLIBC_2.2.5 (fileops.c:517)
==2226==    by 0x48E7C9E: getdelim (iogetdelim.c:120)
==2226==    by 0x109CA0: main (in /workspaces/holbertonschool-simple_shell/hsh)
==2226== 
==2226== HEAP SUMMARY:
==2226==     in use at exit: 1,144 bytes in 2 blocks
==2226==   total heap usage: 180 allocs, 178 frees, 15,211 bytes allocated
==2226== 
==2226== LEAK SUMMARY:
==2226==    definitely lost: 0 bytes in 0 blocks
==2226==    indirectly lost: 0 bytes in 0 blocks
==2226==      possibly lost: 0 bytes in 0 blocks
==2226==    still reachable: 1,144 bytes in 2 blocks
==2226==         suppressed: 0 bytes in 0 blocks
==2226== Rerun with --leak-check=full to see details of leaked memory
==2226== 
==2226== For lists of detected and suppressed errors, rerun with: -s
==2226== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## Author

```
Cyril iglesias <iglcyril@gmail.com>
Lupon Lucas <lucaslupon873@gmail.com>
```
