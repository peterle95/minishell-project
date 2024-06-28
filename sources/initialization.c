#include "../includes/minishell.h"

void    init_grouped(t_grouped *command)
{
    int i;

    i = 0;
    command->words = malloc(sizeof(char *) * MAX_NODE);
    command->red_out = malloc(sizeof(char *) * MAX_NODE);
    command->heredoc = malloc(sizeof(char *) * MAX_NODE);
    command->append_out = malloc(sizeof(char *) * MAX_NODE);
    command->pipe = malloc(sizeof(char *) * MAX_NODE);
    
    // Initialize all pointers to NULL
    while (i < MAX_NODE) 
    {
        command->words[i] = NULL;
        command->red_out[i] = NULL;
        command->heredoc[i] = NULL;
        command->append_out[i] = NULL;
        command->pipe[i] = NULL;
        i++;
    }
    
    command->red_in = NULL;
    command->cmd_ind = 0;
    command->next = NULL;
} 
