/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:20 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/07/01 16:45:20 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void free_grouped(void *content)
{
    t_grouped *command = (t_grouped *)content;
    free_array(command->words);
    free_array(command->red_in);
    free_array(command->red_out);
    free_array(command->heredoc);
    free_array(command->append_out);
    free_array(command->pipe);
    free(command);
}

int	error_return(char *str, int opt)
{
	// add errno? errnum?
	if (opt == 1)
		ft_putstr_fd(str, 2);
	if (opt == 0)
		perror(str);
	return (-1);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	success_exit(char *str)
{
	ft_putstr_fd(str, 1);
    exit(EXIT_SUCCESS);
}

