/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:13:03 by Henriette         #+#    #+#             */
/*   Updated: 2024/06/27 16:56:46 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute(t_grouped *command, char **env, int	num_cmd)
{
	if (num_cmd == 1)
		run_command(command, env);
	/*else
	{
		make_pipes etc.
	}*/
}
