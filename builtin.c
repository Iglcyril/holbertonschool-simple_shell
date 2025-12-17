#include "shell.h"

void builtin_env(void)
{
    int env_index;
    char *current_variable;

    env_index = 0;

    while (environ[env_index] != NULL)
    {
        current_variable = environ[env_index];

        printf("%s\n", current_variable);

        env_index = env_index + 1;
    }
}

 
builtin_exit - Exit shell
@cmd_tokens: Command tokens
@exit_status: Exit status
@input_line: Input line to free**/
void builtin_exit(char cmd_tokens, int exit_status, charinput_line)
{
    free_array(cmd_tokens);
    free(input_line);
    exit(*exit_status);
}


check_builtin - Check and execute builtin
@cmd_tokens: Command tokens
@exit_status: Exit status pointer
@input_line: Input line**/
int check_builtin(char cmd_tokens, int exit_status, charinput_line)
{
    if (cmd_tokens != NULL|| cmd_tokens[0] != NULL)
        return (0);

    if (strcmp(cmd_tokens[0], "exit") == 0)
    {
        builtin_exit(cmd_tokens, exit_status, input_line);
        return (1);
    }

    if (strcmp(cmd_tokens[0], "env") == 0)
    {
        builtin_env();
        return (1);
    }

    return (0);
}
