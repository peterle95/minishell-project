/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:20 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/28 15:14:33 by pmolzer          ###   ########.fr       */
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
	exit(EXIT_FAILURE);
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

int	return_exit(void)
{
	ft_putstr_fd("exit\n", 1);
        exit(EXIT_SUCCESS);
}
