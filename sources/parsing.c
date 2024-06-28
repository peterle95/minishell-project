/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:41:56 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/28 15:15:23 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
void    command_execution(char *line, char **env)
{
    t_input input;
    int i;

    i = 0;
    if (i > 0)
    {*/
        /*create different files for each built-in (norm)*/
      /*  if (ft_strcmp(input.words[0], "exit") == 0)
        {
            ft_putstr_fd("exit\n", 1);
            exit(EXIT_SUCCESS);
        }
        else if (ft_strcmp(input.words[0], "cd") == 0)
        {
            if (i > 1)
                chdir(input.words[1]);
            else
                ft_putstr_fd("cd: missing argument\n", 2);
        }
        else
        {
            run_command(env);
        }
    }
}
*/
void null_terminate_arrays(t_grouped *command, int word_count, int red_out_count, 
int heredoc_count, int append_count, int pipe_count)
{
    if (word_count < MAX_NODE) command->words[word_count] = NULL;
    if (red_out_count < MAX_NODE) command->red_out[red_out_count] = NULL;
    if (heredoc_count < MAX_NODE) command->heredoc[heredoc_count] = NULL;
    if (append_count < MAX_NODE) command->append_out[append_count] = NULL;
    if (pipe_count < MAX_NODE) command->pipe[pipe_count] = NULL;
}

void assign_token(t_grouped *command, TokenType token_type, char **token, int *word_count, 
int *red_out_count, int *heredoc_count, int *append_count, int *pipe_count)
{
    if (token_type == TOKEN_REDIRECT_IN)
    {
        *token = ft_strtok(NULL, " \t\n");
        if (*token != NULL)
        {
            if (command->red_in)
                free(command->red_in);
            command->red_in = ft_strdup(*token);
        }
    }
    else if (token_type == TOKEN_REDIRECT_OUT)
    {
        *token = ft_strtok(NULL, " \t\n");
        if (*token != NULL)
            command->red_out[(*red_out_count)++] = ft_strdup(*token);
    }
    else if (token_type == TOKEN_REDIRECT_APPEND)
    {
        *token = ft_strtok(NULL, " \t\n");
        if (*token != NULL)
            command->append_out[(*append_count)++] = ft_strdup(*token);
    }
    else if (token_type == TOKEN_HEREDOC)
    {
        *token = ft_strtok(NULL, " \t\n");
        if (*token != NULL)
            command->heredoc[(*heredoc_count)++] = ft_strdup(*token);
    }
    else if (token_type == TOKEN_PIPE)
    {
        command->pipe[(*pipe_count)++] = ft_strdup("|");
        command->cmd_ind++;
    }
    else if (token_type == TOKEN_WORD)
    {
        command->words[(*word_count)++] = ft_strdup(*token);
    }
}


TokenType get_token_type(const char *token)
{
    if (ft_strncmp(token, "|", 2) == 0)
        return TOKEN_PIPE;
    else if (ft_strncmp(token, "<", 2) == 0)
        return TOKEN_REDIRECT_IN;
    else if (ft_strncmp(token, ">", 2) == 0)
        return TOKEN_REDIRECT_OUT;
    else if (ft_strncmp(token, ">>", 3) == 0)
        return TOKEN_REDIRECT_APPEND;
    else if (ft_strncmp(token, "<<", 3) == 0)
        return TOKEN_HEREDOC;
    else
        return TOKEN_WORD;
} 

void parse(t_grouped *command, char *line)
{
    int i = 0;
    char *token;
    TokenType token_type;
    int word_count = 0;
    int red_out_count = 0;
    int heredoc_count = 0;
    int append_count = 0;
    int pipe_count = 0;

    if (command == NULL || line == NULL) 
    {
        printf("Error: Null pointer passed to parse\n");
        return;
    }
    if (command->words == NULL || command->red_out == NULL) 
    {
        printf("Error: Memory allocation failed\n");
        return;
    }
    token = ft_strtok(line, " \t\n");
    while (token != NULL && i < MAX_NODE - 1) 
    {
        token_type = get_token_type(token);
        assign_token(command, token_type, &token, &word_count, 
        &red_out_count, &heredoc_count, &append_count, &pipe_count);
        printf("Token: %i --> type: %i\n", i, token_type);
        if (token_type != TOKEN_REDIRECT_IN && token_type != TOKEN_REDIRECT_OUT && 
            token_type != TOKEN_REDIRECT_APPEND && token_type != TOKEN_HEREDOC)
        {
            token = ft_strtok(NULL, " \t\n");
        }
        i++;
    }
    null_terminate_arrays(command, word_count, red_out_count, 
    heredoc_count, append_count, pipe_count);;
}
