#include "../includes/minishell.h"

void    init_grouped(t_grouped *grouped)
{
    grouped->words = NULL;
    grouped->red_in = NULL;
    grouped->red_out = NULL;
    grouped->cmd_ind = 0;
    grouped->next = NULL;
} 
