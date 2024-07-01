/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:43:51 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/01 22:04:59 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>


#define MAX_ARGS 500
#define MAX_NODE 100
#define PERR 0
#define PRIN 1

typedef struct s_grouped
{
	char **words;
	char **red_in; //jede input redirection einzeln speichern 
	char **red_out;  //jede output redirection einzeln speichern
	char **heredoc;
	char **append_out;
	char **pipe;
	int cmd_ind;
	struct s_grouped *next;
} t_grouped;

typedef enum TokenType {
  TOKEN_PIPE,
  TOKEN_REDIRECT_IN,
  TOKEN_REDIRECT_OUT,
  TOKEN_REDIRECT_APPEND,
  TOKEN_HEREDOC,
  TOKEN_WORD
} TokenType;

/*
typedef struct s_input
{
	char **words;
	char **command;
	char **tokens;
	int	index;
	struct s_input *prev;
	struct s_input *next;
} t_input;*/


//exit and free functions
int	error_return(char *str, int opt);
void	free_array(char **str);
int	success_exit(char *str);


//command execution functions - simple, taken from pipex, to be adjusted according to different input structure
//void	run_command_oldinput(char *line, char **env);
char	*find_cmd_file(char **cmd, char **env);
char	*get_paths(char **env, char *name);
void	fork_and_execute(char **cmd, char *cmd_file, char **env);
char	*ft_trim(char *line, char c);
void	run_command(t_grouped *command, char **env);
void	set_input(t_grouped *command);
void	execute(t_grouped *command, char **env, int	num_cmd);

// redirection and pipe functions
int	check_and_redirect(t_grouped *command);
int	redirection_in(t_grouped *command, int i);
int	redirection_out(t_grouped *command, int i);
int	save_in_out(int	*stdin_copy, int *stdout_copy);
int	restore_in_out(int	*stdin_copy, int *stdout_copy);
void	set_fake_redirection(t_grouped *command);


// singal handeling
void    signal_handling(int sig);

// checker for input in the cmd line
int check_line(char *line);

// parsing
void parse(t_list **command_list, char *line);
char *ft_strtok(char *str, char *delim);

// initialization
void    init_grouped(t_grouped *grouped);
#endif
