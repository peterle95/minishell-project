/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:00:49 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/28 16:54:17 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    signal_handling(int sig)
{
    if (sig == SIGINT)
    {
        // Handle Ctrl+C
       // printf("Caught signal SIGINT %d\n", sig); // H: bash printed das nicht
        // Handle SIGINT (Ctrl + C)
        rl_replace_line("", 0);
        ft_putstr_fd("\n", 1);
        rl_on_new_line();
        rl_redisplay();
    }
    else if (sig == SIGQUIT)
    {
        // printf("Caught signal SIGQUIT %d\n", sig); // H: bash printed das nicht
        // Handle SIGQUIT (Ctrl + \)
        rl_replace_line("", 0);
        ft_putstr_fd("Quit: ", 1);
        ft_putnbr_fd(sig, 1);
        ft_putstr_fd("\n", 1);
    }
}
