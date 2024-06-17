/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:43:51 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/17 19:00:19 by hzimmerm         ###   ########.fr       */
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

//exit and free functions
int	error_return(char *str, int opt);
void	free_array(char **str);

//command execution functions - simple, taken from pipex, to be adjusted according to different input structure
void	run_command(char *line, char **env);
char	*find_cmd_file(char **cmd, char **env);
char	*get_paths(char **env, char *name);
void	fork_and_execute(char **cmd, char *cmd_file, char **env);


#endif
