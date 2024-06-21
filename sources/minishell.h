/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:43:51 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/21 18:04:58 by pmolzer          ###   ########.fr       */
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

typedef struct s_input
{
	char **words;
	char **command;
	char **tokens;
	int	index;
	struct s_input *prev;
	struct s_input *next;
} t_input;



//exit and free functions
int	error_return(char *str, int opt);
void	free_array(char **str);

//command execution functions - simple, taken from pipex, to be adjusted according to different input structure
void	run_command(char *line, char **env);
char	*find_cmd_file(char **cmd, char **env);
char	*get_paths(char **env, char *name);
void	fork_and_execute(char **cmd, char *cmd_file, char **env);
char	*ft_trim(char *line, char c);
void	run_command_newinput(char **env);

// singal handeling
void    signal_handeling(int signal);

// input checker
int check_line(char *line);

// initializing struct 
void    init_input(t_input *mini_input)

#endif
