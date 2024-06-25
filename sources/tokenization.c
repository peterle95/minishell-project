/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:21:57 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/24 16:21:57 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
"count" is initialized to 0 to keep track of the number of matching characters.
"pointer" is used to iterate through the delimiter string.
Outer Loop:
Iterates through each character of "string" until the null terminator ('\0') is reached.
Inner Loop:
For each character in string, it iterates through delimiter to check for a match.
If a match is found (*string == *pointer), the inner loop breaks.*/
static size_t first_delimiters(char *string, char *delimiter)
{
    size_t count = 0;
    char *pointer;
    
    while (*string != '\0')
    {
        pointer = delimiter; // resets pointer to beginning of "delimiter" after ever outer loop iteration
        while (*pointer != '\0')
        {
            if (*string == *pointer)
                break;
            pointer++;
        }
        if (*pointer == '\0')
            return count;
        count++;
        string++;
    }
    return (count);
}

/*It searches the string "string" for the first occurrence of any character from the string "delimiter".
For each character in "string", it compares it with every character in "delimiter"
If a match is found, it immediately returns a pointer to that position in "string"
If no match is found after checking all characters in "string", it returns NULL*/
static char *breakup_string(char *string, char *delimiter)
{
    char *pointer;
    
    while (*string != '\0')
    {
        pointer = delimiter;
        while (*pointer != '\0')
        {
            if (*string == *pointer)
                return (char *)string;
            pointer++;
        }
        string++;
    }
    return (NULL);
}

/*The ft_strtok function is designed to split a string (str) into a series of tokens, 
using a set of specified delimiters (delim). The function uses a static variable next_token 
to keep track of the current position in the input string between consecutive calls.

Handling of initial input: 
When ft_strtok is first called with a new input string, str will not be null. 
In this case, next_token is initialized with the address of the input string, indicating 
that processing should start from the beginning of the string.
Skipping initial delimiters: 
the function then uses first_delimiters to skip any initial delimiters in the input string. 
first_delimiters returns the number of characters in the input string that match any of the 
delimiters. Using next_token += strspn(next_token, delim) effectively moves the next_token pointer past 
any initial delimiters, placing it at the beginning of the first token or at the end 
of the string if only delimiters are present.
End token delimiter search: breakup_string is used to find the first occurrence of any 
delimiter in the input string, starting at the current position of next_token. 
If a delimiter is found, next_token is updated to point to it, marking the end of the current token.
Token termination:
if a delimiter has been found (i.e., next_token is not NULL), 
the character that next_token points to is replaced with a null character (\0). 
This action effectively terminates the current token, making it a valid null-terminated string.
Advance to next token: If a delimiter has been found, 
next_token is incremented by 1 to advance to the next character after the delimiter. 
This step prepares the function for the extraction of the next token in the next call*/
char *ft_strtok(char *str, char *delim)
{
    static char *next_token;
    char *parsed_token;

    if (str)
        next_token = str;
    else if (!next_token)
        return (0);

    // Skip leading delimiters
    next_token += first_delimiters(next_token, delim);
    if (*next_token == '\0')
    {
        next_token = 0;
        return 0;
    }

    parsed_token = next_token;
    // Exctracts the word out of the string
    next_token = breakup_string(parsed_token, delim);
    if (next_token)
    {
        *next_token = '\0';
        next_token++;
    }
    else
    {
        next_token = 0;
    }

    return (parsed_token);
}