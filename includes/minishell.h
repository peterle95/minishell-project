/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:43:51 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/25 15:18:23 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

#define MAX_ARGS 100

typedef struct s_grouped
{
	char **words;
	char *red_in; //immer die naechste inredirection ersetzt die davor 
	char **red_out;  //jede output redirection einzeln speichern
	//heredoc
	//append
	int cmd_ind;
	struct s_grouped *next;
} t_grouped;

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

//command execution functions - simple, taken from pipex, to be adjusted according to different input structure
//void	run_command_oldinput(char *line, char **env);
char	*find_cmd_file(char **cmd, char **env);
char	*get_paths(char **env, char *name);
void	fork_and_execute(char **cmd, char *cmd_file, char **env);
char	*ft_trim(char *line, char c);
void	run_command(char **env);

// singal handeling
void    signal_handling(int signal);

// checker for input in the cmd line
int check_line(char *line);

// parsing
void parse(char *line, char **env);



void	run_command_new(char **env, t_group *command);
void	get_input(char *line, char **env);

#endif
