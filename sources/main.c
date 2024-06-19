/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:51:58 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/17 19:29:07 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
	char    *line;
	if((ac = 1) || (!ac && !av))
	{
		printf("minishell: no arguments provided\n");
		return(1);
	}
	else 
	{
		av = NULL;
		return (0);
		/* do we need to handle what bash does when run with one or more arguments?
		---> // check if argv[1] is directory, in that case give error message that it is directory. if it's file then execute file ?
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": ", 2);
		return (error_return("no such file or directory\n", 1));
		P: I would insert the while loop belove in this scope. And then, in the parsing part we look if there are multiple arguments,
		and tokenize them. We should check the type of the tokens, and if they are not what is expected, then throw an error message.
		Does it make sense?
		*/
	}
	// Register signal handlers
	signal_handeling(1); 
	while(1)
	{
		line = readline("$>");
        if(line == NULL)
		{
			printf("exit\n");
			break;
		}
           	//free
		if (*line) // <-- this checks that entered line is not empty (empty lines are not stored in history)
			add_history(line);
/*       	if(check for line content)
           	//error_management
        	else
            	//p go to parsing and execution*/
	    	//parsing : divide line up into command table data structure
	    	//execution : take data structure type and execute 
		run_command(line, env);
        	// free everything
		free(line);
	}
	return (0);
}
