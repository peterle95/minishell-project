/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:41:56 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/25 17:14:54 by hzimmerm         ###   ########.fr       */
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

void parse(char *line, char **env)
{
    t_input input;
    char *token;
    int i = 0;

    i = 0;
    init_input(&input);
    // Tokenize the input line
    token = strtok(line, " \t\n");
    while (token != NULL && i < MAX_ARGS - 1)
    {
        input.words[i++] = ft_strdup(token);
        token = strtok(NULL, " \t\n");
    }
    input.words[i] = NULL;

    // Simple command execution
    command_execution(line, env);

    free_array(input.words);
}*/
