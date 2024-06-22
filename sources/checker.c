/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:53:40 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/21 18:26:55 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


/*Handle that if there is a "" or a '' around a metacharacter (operator?) it should be extracted.
--> Ask/check slack for this*/
int check_line(char *line) {
    int i = 0;
    int in_single_quote = 0; // Flag to track single quote state
    int in_double_quote = 0; // Flag to track double quote state

    if (!line) 
    {
        ft_putstr_fd("Error: NULL input\n", 2);
        return 1;
    }
    while (line[i]) {
        if (line[i] == '\'' && !in_double_quote) {
            // Single quote encountered, toggle in_single_quote flag
            in_single_quote = !in_single_quote;
        } else if (line[i] == '"' && !in_single_quote) {
            // Double quote encountered, toggle in_double_quote flag
            in_double_quote = !in_double_quote;
        } else if (line[i] == '\\' && in_double_quote) {
            // Backslash encountered within double quotes, skip next character
            i++; // Skip the character after backslash
        } else if ((line[i] == ';' || line[i] == '\\') && !in_single_quote && !in_double_quote) {
            // Forbidden character encountered outside quotes
            fprintf(stderr, "Forbidden special character, please don't use '%c' outside quotes\n", line[i]);
            return 1;
        } else if (line[i] == '$' && in_double_quote) {
            // Dollar sign allowed within double quotes, continue processing
            // (no special handling needed here)
        }
        i++;
    }

    // Check for unclosed quotes before returning
    if (in_single_quote) {
        ft_putstr_fd("Unclosed single quote", 1);
        return (1);
    } else if (in_double_quote) {
        ft_putstr_fd("Unclosed double quote", 1);
        return (1);
    }

    return (0); // No errors found
}