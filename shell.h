#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
extern char *shell_name;

void strip_newline(char *input_str, ssize_t *str_len);
int token_count(const char *input_str, const char *delim);
char **split_string(char *input_str, char *delim);
char *clean_quotes(char *token);
void free_array(char **array);
int exec_cmd(char **argv);
void builtin_env(void);
void builtin_exit(char **cmd_tokens, int *exit_status, char *input_line);
int check_builtin(char **cmd_tokens, int *exit_status, char *input_line);


#endif
