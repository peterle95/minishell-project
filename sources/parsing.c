/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:41:56 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/25 22:45:50 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
void    command_execution(char *line, char **env)
{
    t_input input;
    int i;

    i = 0;
    if (i > 0)
    {*/
        /*create different files for each built-in (norm)*/
      /*  if (ft_strcmp(input.words[0], "exit") == 0)
        {
            ft_putstr_fd("exit\n", 1);
            exit(EXIT_SUCCESS);
        }
        else if (ft_strcmp(input.words[0], "cd") == 0)
        {
            if (i > 1)
                chdir(input.words[1]);
            else
                ft_putstr_fd("cd: missing argument\n", 2);
        }
        else
        {
            run_command(env);
        }
    }
}

TokenType get_token_type(const char *token)
{
    if (ft_strncmp(token, "|", 2) == 0)
        return TOKEN_PIPE;
    else if (ft_strncmp(token, "<", 2) == 0)
        return TOKEN_REDIRECT_IN;
    else if (ft_strncmp(token, ">", 2) == 0)
        return TOKEN_REDIRECT_OUT;
    else if (ft_strncmp(token, ">>", 3) == 0)
        return TOKEN_REDIRECT_APPEND;
    else if (ft_strncmp(token, "<<", 3) == 0)
        return TOKEN_HEREDOC;
    else
        return TOKEN_WORD;
} */

void parse(t_grouped *command, char *line)
{
    int i;

    i = 0;
    command->words = malloc(sizeof(char *) * MAX_ARGS);
    if (command == NULL || line == NULL) {
        printf("Error: Null pointer passed to parse\n");
        return;
    }
    init_grouped(command);
    command->words[i] = ft_strtok(line, " \t\n");
    while (command->words[i] != NULL && i < MAX_ARGS - 1)
    {
        printf("Token %d: %s\n", i, command->words[i]);
        i++;
        command->words[i] = ft_strtok(NULL, " \t\n");
    }
    command->words[i] = NULL; 
}
