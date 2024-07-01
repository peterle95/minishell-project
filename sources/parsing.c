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
int heredoc_count, int append_count, int pipe_count, int red_in_count)
{
    if (word_count < MAX_NODE) command->words[word_count] = NULL;
    if (red_out_count < MAX_NODE) command->red_out[red_out_count] = NULL;
    if (red_in_count < MAX_NODE) command->heredoc[red_in_count] = NULL;
    if (heredoc_count < MAX_NODE) command->heredoc[heredoc_count] = NULL;
    if (append_count < MAX_NODE) command->append_out[append_count] = NULL;
    if (pipe_count < MAX_NODE) command->pipe[pipe_count] = NULL;
}

void assign_token(t_grouped *command, TokenType token_type, char **token, int *word_count, 
int *red_out_count, int *heredoc_count, int *append_count, int *pipe_count, int*red_in_count)
{
    if (token_type == TOKEN_REDIRECT_IN)
    {
        *token = ft_strtok(NULL, " \t\n");
        if (*token != NULL)
        {
            if (command->red_in)
            {
             command->red_in[(*red_in_count)++] = ft_strdup(*token);
             printf("\n%s", command->red_in[0]);
             // printf("Stored in -> Redirection In: %s\n", command->red_in[*red_in_count - 1]);
             }
        }
    }
    else if (token_type == TOKEN_REDIRECT_OUT)
    {
        *token = ft_strtok(NULL, " \t\n");
        if (*token != NULL)
        {
            command->red_out[(*red_out_count)] = ft_strdup(*token);
            printf("\n%s", command->red_out[0]);
        }
    }
    else if (token_type == TOKEN_REDIRECT_APPEND)
    {
        *token = ft_strtok(NULL, " \t\n");
        if (*token != NULL)
        {
            command->append_out[(*append_count)++] = ft_strdup(*token);
            printf("\n%s", command->append_out[0]);
        }
    }
    else if (token_type == TOKEN_HEREDOC)
    {
        *token = ft_strtok(NULL, " \t\n");
        if (*token != NULL)
        {
            command->heredoc[(*heredoc_count)++] = ft_strdup(*token);
            printf("\n%s", command->heredoc[0]);
        }
    }
    else if (token_type == TOKEN_PIPE)
    {
        command->pipe[(*pipe_count)++] = ft_strdup("|");
        printf("\n%s", command->pipe[0]);
        command->cmd_ind++;
    }
    else if (token_type == TOKEN_WORD)
    {
        command->words[(*word_count)++] = ft_strdup(*token);
        printf("\n%s", command->words[0]);
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

void parse(t_list **command_list, char *line)
{
    t_grouped   *current_command = NULL;
    t_list  *new_node = NULL;
    int i;
    char *token;
    TokenType token_type;
    int word_count;
    int red_out_count;
    int red_in_count;
    int heredoc_count;
    int append_count;
    int pipe_count;

    i = 0;
    word_count = 0;
    red_out_count = 0;
    red_in_count = 0;
    heredoc_count = 0;
    append_count = 0;
    pipe_count = 0;

    current_command = malloc(sizeof(t_grouped));
    if (!current_command)
    {
        printf("Error: Memory allocation failed\n");
        return;
    }
    init_grouped(current_command);
    token = ft_strtok(line, " \t\n");
    while (token != NULL && i < MAX_NODE - 1)
    {
        token_type = get_token_type(token);
        if (token_type == TOKEN_PIPE)
        {
            new_node = ft_lstnew(current_command);
            ft_lstadd_back(command_list, new_node);
            
            current_command = malloc(sizeof(t_grouped));
            if (!current_command)
            {
                printf("Error: Memory allocation failed\n");
                return;
            }
            word_count = 0;
            red_out_count = 0;
            red_in_count = 0;
            heredoc_count = 0;
            append_count = 0;
        }
        else
        {
            assign_token(current_command, token_type, &token, &word_count,
                         &red_out_count, &heredoc_count, &append_count, &pipe_count,
                         &red_in_count);
        }
        
        if (token_type != TOKEN_REDIRECT_IN && token_type != TOKEN_REDIRECT_OUT &&
            token_type != TOKEN_REDIRECT_APPEND && token_type != TOKEN_HEREDOC)
        {
            token = ft_strtok(NULL, " \t\n");
        }
        i++;
    }
    // Add the last command to the list
    new_node = ft_lstnew(current_command);
    ft_lstadd_back(command_list, new_node);

    null_terminate_arrays(current_command, word_count, red_out_count,
                          heredoc_count, append_count, pipe_count, red_in_count);
}