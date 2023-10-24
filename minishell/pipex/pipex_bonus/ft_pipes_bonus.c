/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:16:59 by rrimonte          #+#    #+#             */
/*   Updated: 2023/05/11 18:02:16 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * The function creates pipes and forks child processes to execute commands
 * in a linked list.
 */
void	create_pipes(t_data *g_data, int argc)
{
	ft_backward_node(g_data);
	while (g_data->i <= argc - 3)
	{
		if (g_data->i != argc - 3)
			pipe(g_data->cmd_lst->fd);
		g_data->pid = fork();
		if (g_data->pid == 0)
			child(g_data, argc);
		else
		{
			close(g_data->cmd_lst->fd[WRITE_O]);
			if (g_data->berrorinf == 1)
				g_data->berrorinf = 0;
			if (g_data->i < argc - 3)
				g_data->cmd_lst = g_data->cmd_lst->next;
			g_data->i++;
		}
	}
	close(g_data->infl);
	close(g_data->outfl);
	ft_backward_node(g_data);
	ft_forward_node(g_data);
	g_data->i = 1;
	while (g_data->i++ <= argc - 3)
		wait(&g_data->status);
}

void	child(t_data *g_data, int argc)
{
	g_data->cmd_rute = get_cmd_path(g_data);
	if (g_data->i == 1 || (g_data->i == 2 && g_data->b_here_doc == 1))
	{
		dup2(g_data->infl, STDIN_FILENO);
		close(g_data->infl);
	}
	else
	{
		dup2(g_data->cmd_lst->previous->fd[READ_O], STDIN_FILENO);
		close(g_data->cmd_lst->previous->fd[READ_O]);
		if (g_data->i == argc - 3)
		{			
			dup2(g_data->outfl, STDOUT_FILENO);
			execve(g_data->cmd_rute, g_data->cmd_lst->cmd, NULL);
			ft_error(4);
		}
	}
	close (g_data->cmd_lst->fd[READ_O]);
	dup2(g_data->cmd_lst->fd[WRITE_O], STDOUT_FILENO);
	close (g_data->cmd_lst->fd[WRITE_O]);
	if (g_data->berrorinf == 1)
		exit(0);
	execve(g_data->cmd_rute, g_data->cmd_lst->cmd, NULL);
	ft_error(4);
}

char	*get_cmd_path(t_data *g_data)
{
	char	*tmp;
	char	*command;

	if (g_data->cmd_lst->cmd[0] == 0)
		ft_error(3);
	if (access(g_data->cmd_lst->cmd[0], X_OK) && g_data->b_env == 1)
		return (g_data->cmd_lst->cmd[0]);
	else if (g_data->b_env == 1)
	{
		ft_error(3);
		exit (0);
	}
	while (g_data->cmd_paths && g_data->cmd_paths[0] != NULL)
	{
		tmp = ft_strjoin(g_data->cmd_paths[0], "/");
		command = ft_strjoin(tmp, g_data->cmd_lst->cmd[0]);
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		g_data->cmd_paths++;
	}
	ft_error(3);
	return (NULL);
}
