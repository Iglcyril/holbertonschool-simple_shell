#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void strip_newline(char *input_str, ssize_t *str_len);
int token_count(const char *input_str, const char *delim);
char **split_string(char *input_str, char *delim);
char *clean_quotes(char *token);
void free_array(char **array);
char *get_env_value(const char *name, char **envp);
int exec_cmd(char **argv, char **envp, char *prog_name);
void builtin_env(char **envp);
void builtin_exit(int *exit_status, char *input_line);
int check_builtin(char **cmd_tokens, int *exit_status,char *input_line, char **envp);

#endif
