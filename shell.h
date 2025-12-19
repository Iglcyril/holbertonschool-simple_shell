#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *build_path(char *dir_path, char *cmd_name);
int search_in_path(char **path_dirs, char **cmd_args, char **envp, char *prog_name);
int exec_direct(char **cmd_args, char **envp, char *prog_name);
int find_and_execute(char **cmd_args, char **envp, char *prog_name);

void builtin_env(char **envp);
void builtin_exit(int *exit_status, char *input_line);
int check_builtin(char **cmd_tokens, int *exit_status,char *input_line, char **envp);

char *clean_quotes(char *token);

int exec_cmd(char **argv, char **envp, char *prog_name);

void free_array(char **array);

char *get_env_value(const char *name, char **envp);

int main(int argc, char **argv, char **envp);

char **split_string(char *input_str, char *delim);

void strip_newline(char *input_str, ssize_t *str_len);

int token_count(const char *input_str, const char *delim);

#endif
