/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:00:49 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/19 12:00:49 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* static void handle_SIGINT(int sig)
{
    printf("Caught signal SIGINT %d\n", sig);
    // Handle SIGINT (Ctrl + C)
    rl_replace_line("", 0);
    ft_putstr_fd("\n", 1);
    rl_on_new_line();
    rl_redisplay();
}

static void handle_SIGQUIT(int sig)
{
    printf("Caught signal SIGQUIT %d\n", sig);
    // Handle SIGQUIT (Ctrl + \)
    rl_replace_line("", 0);
    ft_putstr_fd("Quit: ", 1);
    ft_putnbr_fd(sig, 1);
    ft_putstr_fd("\n", 1);
} */

void    signal_handeling(int sig)
{
    if (sig == SIGINT)
    {
        // Handle Ctrl+C
        printf("Caught signal SIGINT %d\n", sig);
        // Handle SIGINT (Ctrl + C)
        rl_replace_line("", 0);
        ft_putstr_fd("\n", 1);
        rl_on_new_line();
        rl_redisplay();
    }
    else if (sig == SIGQUIT)
    {
        printf("Caught signal SIGQUIT %d\n", sig);
        // Handle SIGQUIT (Ctrl + \)
        rl_replace_line("", 0);
        ft_putstr_fd("Quit: ", 1);
        ft_putnbr_fd(sig, 1);
        ft_putstr_fd("\n", 1);
    }
}
