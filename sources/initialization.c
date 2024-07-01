/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:01:38 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/01 17:47:26 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
   // command->next = NULL;
} 

void init_list(t_list *command_list)
{
    t_grouped *initial_command;

    if (command_list == NULL)
        return;

    initial_command = (t_grouped *)malloc(sizeof(t_grouped));
    if (!initial_command)
    {
        printf("Error: Memory allocation failed in init_list\n");
        exit(EXIT_FAILURE);
    }

    init_grouped(initial_command);

    command_list->content = initial_command;
    command_list->next = NULL;
}
