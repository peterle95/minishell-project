/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:13:03 by Henriette         #+#    #+#             */
/*   Updated: 2024/06/28 22:51:53 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_fake_redirection(t_grouped *command)
{
	command->red_in = malloc(5 * sizeof(char *));
	command->red_in[0] = "file1";
	command->red_in[1] = "file2";
	command->red_in[2] = NULL;

	command->red_out = malloc(5 * sizeof(char *));
	command->red_out[0] = "file3";
	command->red_out[1] = "file4";
	command->red_out[2] = NULL;	
}

/* this function handles redirections, sets up pipes in case of multiple commands and launches the command execution */
void	execute(t_grouped *command, char **env, int	num_cmd)
{
	int	stdin_copy;
	int	stdout_copy;

	//set_fake_redirection(command);
	if (num_cmd == 0)
		return;
	if (save_in_out(&stdin_copy, &stdout_copy) == -1) // this function saves the stdin + stdout in a copy, before they potentially get replaced by a file
		return;
	if (num_cmd == 1)
	{
		/* this function below returns 0 if there are no redirections or if redirections were successfully made. 
		It returns 1 if there is a problem with making the redirections, for example in case of wrong permissions */
		if (check_and_redirect(command) == -1)
				return;
		run_command(command, env);
	}
	/*else
	{
		make_pipes etc.
	}*/	
	restore_in_out(&stdin_copy, &stdout_copy);
	free(command->red_in);
	free(command->red_out);
}

int	check_and_redirect(t_grouped *command)
{
	int	i;
	if (command->red_in)
	{
		i = 0;
		while (command->red_in[i])
		{
			if (redirection_in(command, i) == -1)
				return (-1);
			i++;
		}
	}
	if (command->red_out)
	{
		i = 0;
		while (command->red_out[i])
		{
			if (redirection_out(command, i) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}

/* separated function for shortening the redirection while loop */
int	redirection_out(t_grouped *command, int i)
{
	int	fd;
	
	fd = open(command->red_out[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (error_return(command->red_out[i], PERR));
	if (dup2(fd, 1) == -1)
	{
		// need to close copy of stdout?
		close(fd);
		return (error_return("dup2", PERR));
	}
	close(fd);
	return (0);
}

/* separated function for shortening the redirection while loop */
int	redirection_in(t_grouped *command, int i)
{
	int	fd;
	
	if (access(command->red_in[i], R_OK) == -1)
		return (error_return(command->red_in[i], PERR));
	fd = open(command->red_in[i], O_RDONLY);
	if (fd == -1)
		return (error_return("open", PERR));
	if (dup2(fd, 0) == -1)
	{
		// need to close copy of stdin?
		close(fd);
		return (error_return("dup2", PERR));
	}
	close(fd);
	return (0);
}

/* this function saves the original standard input and standard output in the corresponding int variable before potential redirection */
int	save_in_out(int	*stdin_copy, int *stdout_copy)
{
	*stdin_copy = dup(STDIN_FILENO); // save stdin to reset later
	*stdout_copy = dup(STDOUT_FILENO);
	if (*stdin_copy == -1 || *stdout_copy == -1)
		return (error_return("dup", PERR));
	return (0);
}

/* this function restores the original standard in and out after the command has been executed with their potential redirection */
int	restore_in_out(int	*stdin_copy, int *stdout_copy)
{
	if (dup2(*stdin_copy, STDIN_FILENO) == -1 || dup2(*stdout_copy, STDOUT_FILENO) == -1) //reset to stdin + stdout
	{
		close(*stdin_copy);
		close(*stdout_copy);
		return (error_return("dup2", PERR));
	}
	close(*stdin_copy);
	close(*stdout_copy);
	return (0);
}
	
