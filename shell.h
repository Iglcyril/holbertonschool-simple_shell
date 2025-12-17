#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void strip_newline(char *input_str, ssize_t *str_len);
int main(int argc, char **argv);
int exec_cmd(char *cmd);
int token_count(const char *input_str, const char *delim);


#endif
