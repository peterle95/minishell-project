/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:13:03 by Henriette         #+#    #+#             */
/*   Updated: 2024/06/28 12:28:13 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute(t_grouped *command, char **env, int	num_cmd)
{
	if (num_cmd == 0)
		return;
	if (num_cmd == 1)
		run_command(command, env);
	/*else
	{
		make_pipes etc.
	}*/
}
