/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:51:58 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/16 14:51:58 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int ac, char **av, char **envp)
{
    char    *line;
    
    // handle signals
    while(1)
    {
        line = readline("$>");
        if(line == NULL)
            // free and function for printing exit 
        add_history(line);
        if(/*check for line content*/)
           //error_management
        else
            //p go to parsing and execution
        // free everything
    }

}