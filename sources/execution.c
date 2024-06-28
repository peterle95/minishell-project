/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:13:03 by Henriette         #+#    #+#             */
/*   Updated: 2024/06/28 16:56:05 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* this function handles redirections, sets up pipes in case of multiple commands and launches the command execution */
int	execute(t_grouped *command, char **env, int	num_cmd)
{
	/*
	command->red_in = malloc(5 * sizeof(char *));
	command->red_in[0] = "file1";
	command->red_in[1] = "file2";
	command->red_in[2] = NULL;
	*/
	int	stdin_copy;

	if (num_cmd == 0)
		return (1);
	stdin_copy = dup(STDIN_FILENO);
	if (stdin_copy == -1)
		return (error_return("dup", PERR));
	if (num_cmd == 1)
	{
		/* this function below returns 0 if there are no redirections or if redirections were successfully made. 
		It returns 1 if there is a problem with making the redirections, for example in case of wrong permissions */
		if (check_and_redirect(command) == 1)
				return (1);
		run_command(command, env);
	}
	/*else
	{
		make_pipes etc.
	}*/	
	dup2(stdin_copy, STDIN_FILENO);
	close(stdin_copy);
	return (0);
}

int	check_and_redirect(t_grouped *command)
{
	int	i;
	int	fd;

	i = 0;
	if (command->red_in)
	{
		while (command->red_in[i])
		{
			if (access(command->red_in[i], R_OK) == -1)
				return (error_return(command->red_in[i], PERR));
			//open fd, duplicate
			fd = open(command->red_in[i], O_RDONLY);
			if (fd == -1)
				return (error_return("open", PERR));
			if (dup2(fd, 0) == -1)
			{
				close(fd);
				return (error_return("dup2", PERR));
			}
			close(fd);
			i++;
		}
	}
	/*if (command->red_out)
	{
		//handle out redirections
	}*/
	return (0);
}
