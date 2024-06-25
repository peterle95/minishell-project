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

int main(int ac, char **av)
{
	char    *line;
	
	(void)av;
	if (ac != 1)
		av = NULL;
		// MAYBE: take care of arguments to behave like bash (execute bash script, error everything else)
	/* signal(SIGINT, signal_handeling);
    signal(SIGQUIT, signal_handeling); */
	while(1)
	{
		line = readline("$>");
        if(line == NULL || !ft_strncmp(line, "exit", 5)) 
        {
            // This is where Ctrl+D is handled
            ft_putstr_fd("\nexit\n", 1);  // Print newline before "exit"
            break;  // Exit the loop
        }
		if (*line)
			add_history(line);
		if(check_line(line) != 0)
		{
			ft_putstr_fd("exit\n", 1);
			exit(EXIT_SUCCESS);
		}
		else if (*line)
			parse(line);	
        	// free everything
		free(line);
	}
	rl_clear_history();
	return (0);
}
