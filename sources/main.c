/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:51:58 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/20 15:49:37 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
	char    *line;
	
	if (ac != 1)
		av = NULL;
		// MAYBE: take care of arguments to behave like bash (execute bash script, error everything else)
	// Register signal handlers
	signal_handeling(1); 
	while(1)
	{
		line = readline("$>");
        if(line == NULL)
		{
			printf("exit\n");
			exit(EXIT_SUCCESS);
		}
           	//free
		if (*line)
			add_history(line);
/*       	if(check for line content)
           	//error_management
        	else
            	//p go to parsing and execution*/
	    	//parsing : divide line up into command table data structure
	    	//execution : take data structure type and execute 
		if (*line)
			run_command(line, env);
        	// free everything
		free(line);
	}
	return (0);
}
