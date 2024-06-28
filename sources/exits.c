/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:20 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/28 16:25:44 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	error_return(char *str, int opt)
{
	// add errno? errnum?
	if (opt == 1)
		ft_putstr_fd(str, 2);
	if (opt == 0)
		perror(str);
	return (1);
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

