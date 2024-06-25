/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:51:58 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/21 18:15:34 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//H: habe alles auskommentiert von commands und parsing, sodass man das Programm so compilen kann und die minishell loop funktioniert

int main(int ac, char **av, char **env)
{
	char    *line;
	t_grouped *command;
	
	env = NULL;
	command = NULL;
	if (ac != 1)
		av = NULL;
		// MAYBE: take care of arguments to behave like bash (execute bash script, error everything else)
	/* signal(SIGINT, signal_handeling);
    signal(SIGQUIT, signal_handeling); */
	while(1)
	{
		line = readline("$>");
        	if(line == NULL) // This is where Ctrl+D is handled
			return(return_exit());
		if (*line)
		{
			add_history(line);
			/*if(check_line(line) != 0)
				return(return_exit());*/
			//parse(command, line);
			//run_command(command, env);
        		// free everything
			
		}
		free(line);
	}
	rl_clear_history();
	return (0);
}
