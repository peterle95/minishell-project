/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:20:22 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/20 16:22:16 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_command(char *line, char **env)
{
	char	**cmd;
	char	*cmd_file;
	char	*temp;
	
	if (ft_strrchr(line, '/'))
	{
		cmd_file = ft_trim(line, ' ');
		if (access(cmd_file, X_OK) != 0)
		{
			ft_putstr_fd(cmd_file, 2);
			ft_putstr_fd(": command not found\n", 2);
			return;
		}
		temp = ft_strrchr(line, '/') + 1;
		cmd = ft_split(temp, ' ');
		if (cmd_file == NULL || cmd[0] == NULL)
			error_return("ft_strdup", 1);
	}
	else
	{
		cmd = ft_split(line, ' ');
		cmd_file = find_cmd_file(cmd, env);
		if (cmd_file == NULL)
		{
			free(cmd_file);
			free_array(cmd);
			return;
		}
	}
	fork_and_execute(cmd, cmd_file, env);
	free_array(cmd);
	free(cmd_file);
}

char	*ft_trim(char *line, char c)
{
	char	*trim;
	int	i;

	i = 0;
	while (line[i] && line[i] != c)
		i++;
	trim = malloc((i + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != c)
	{
		trim[i] = line[i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
} 

void	fork_and_execute(char **cmd, char *cmd_file, char **env)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
	{
		free_array(cmd);
		free(cmd_file);
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		if (execve(cmd_file, cmd, env) == -1)
			error_return("execve", 0);
	}
	else
		waitpid(pid, &status, 0);
	
}

char	*find_cmd_file(char **cmd, char **env)
{
	char	**paths;
	int		i;
	char	*cmd_file;
	char	*temp;

	i = 0;
	paths = ft_split(get_paths(env, "PATH"), ':');
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		cmd_file = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(cmd_file, X_OK) == 0)
		{
			free_array(paths);
			return (cmd_file);
		}
		else
			free(cmd_file);
		i++;
	}
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_array(paths);
	return (NULL);
}

char	*get_paths(char **env, char *name)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub, name, 4) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}
