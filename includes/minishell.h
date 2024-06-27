/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:43:51 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/27 16:58:17 by Henriette        ###   ########.fr       */
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

#define MAX_ARGS 500

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
int	return_exit(void);

//command execution functions - simple, taken from pipex, to be adjusted according to different input structure
//void	run_command_oldinput(char *line, char **env);
char	*find_cmd_file(char **cmd, char **env);
char	*get_paths(char **env, char *name);
void	fork_and_execute(char **cmd, char *cmd_file, char **env);
char	*ft_trim(char *line, char c);
void	run_command(t_grouped *command, char **env);
void	set_input(t_grouped *command);
void	execute(t_grouped *command, char **env, int	num_cmd);

// singal handeling
void    signal_handling(int signal);

// checker for input in the cmd line
int check_line(char *line);

// parsing
void parse(t_grouped *command, char *line);
char *ft_strtok(char *str, char *delim);

// initialization
void    init_grouped(t_grouped *grouped);

#endif
