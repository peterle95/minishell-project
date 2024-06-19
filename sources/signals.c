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

static void handle_SIGINT(int sig)
{

}

static void handle_SIGQUIT(int sig);
{


}

void    signal_handeling(int handle_signals)
{
    signal(SIGINT, handle_SIGINT);	
	signal(SIGQUIT, handle_SIGQUIT);
}
