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

int main(int ac, char **av, char **env)
{
	char    *line;
	t_list *command_list;
	
	(void)env; // sonst: error: parameter ‘env’ set but not used [-Werror=unused-but-set-parameter]
	command_list = NULL;
	(void)av; // sonst:  error: parameter ‘av’ set but not used [-Werror=unused-but-set-parameter]
	if (ac != 1)
		av = NULL;
		// MAYBE: take care of arguments to behave like bash (execute bash script, error everything else)
	signal(SIGINT, signal_handling);
    signal(SIGQUIT, signal_handling);
	while(1)
	{
		line = readline("$>");
        	if(line == NULL) // This is where Ctrl+D is handled
			{
				//printf("Received Ctrl + D"); H: bash printed das nicht
				return(success_exit("exit\n"));
			}
		if (*line)
		{
			command_list = (t_list *)malloc(sizeof(t_list));
			init_list(command_list);
			add_history(line);
			/* if(check_line(line) != 0)
				return(return_exit()); */
			parse(&command_list, line); // muss man frei lassen sonst:  error: variable ‘command’ set but not used [-Werror=unused-but-set-variable]
			/* H: wenn parse einen int für anzahl of commands ausgeben könnte, wäre amazing (wenn 0 rauskommt, könnte man aus execution direct returnen). z.b. so:
			num_cmd = parse(command, line);
			execution(command, env, num_cmd);
			*/
			//execute(command_list, env, ft_lstsize(command_list)); // das zum checken ob es pipes gibt und redirections, ersetzt wahrscheinlich run_command später
			// run_command(command, env); // muss man frei lassen sonst: error: parameter ‘env’ set but not used [-Werror=unused-but-set-parameter]
        	// free everything
			ft_lstclear(&command_list, free_grouped);
		}
		free(line);
	}
	rl_clear_history(); // H: denke evtl. muss das in den exit Part?
	return (0);
}
