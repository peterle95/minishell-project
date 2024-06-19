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
#include <readline/readline.h>
#include <readline/history.h>

static void handle_SIGINT(int sig)
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
}

void    signal_handeling(int signal_type)
{
    if(signal_type == SIGINT)
        handle_SIGINT(1);
    else if(signal_type == SIGQUIT)
        handle_SIGQUIT(2);
}
