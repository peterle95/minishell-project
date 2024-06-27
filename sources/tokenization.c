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

/*Probably too long, but for now it should do the job*/
char *ft_strtok(char *str, char *delim) {
    static char *saveptr = NULL;
    char *token_start, *token_end;
    char *result;

    // If str is not NULL, initialize saveptr
    if (str != NULL) 
    {
        saveptr = str;
    }

    // If saveptr is NULL or points to end of string, return NULL
    if (saveptr == NULL || *saveptr == '\0') 
    {
        return NULL;
    }

    // Skip leading delimiters
    saveptr += first_delimiters(saveptr, delim);
    if (*saveptr == '\0') 
    {
        return NULL;
    }

    // Find the end of the token
    token_start = saveptr;
    token_end = breakup_string(saveptr, delim);
    
    if (token_end == NULL) 
    {
        // This token finishes the string
        result = strdup(token_start);
        saveptr = NULL;
    } 
    else 
    {
        // Allocate memory for the token and copy it
        result = malloc(token_end - token_start + 1);
        if (result == NULL) 
        {
            return NULL;  // Memory allocation failed
        }
        strncpy(result, token_start, token_end - token_start);
        result[token_end - token_start] = '\0';
        saveptr = token_end + 1;
    }

    return result;
}