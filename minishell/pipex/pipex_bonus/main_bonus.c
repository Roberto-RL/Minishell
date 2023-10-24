/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:02:11 by rrimonte          #+#    #+#             */
/*   Updated: 2023/10/16 18:27:48 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*g_data;
	int		narg;

	narg = 1;
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		narg++;
	if (argc <= narg)
		ft_error(0);
	g_data = malloc(sizeof(t_data));
	if (g_data == NULL)
		return (0);
	ft_check_files(g_data, argc, argv, envp);
	ft_parse(g_data, argc, argv);
	create_pipes(g_data, argc);
	//ft_free_all(g_data, argc);
	unlink("h_d_temp");
	return (0);
}

void	ft_free_matrix(t_data *g_data, int n)
{
	if (n == 0)
	{
		while (g_data->cmd_lst->cmd[g_data->x])
		{
			free(g_data->cmd_lst->cmd[g_data->x]);
			g_data->x++;
		}
		free(g_data->cmd_lst->cmd);
		g_data->x = 0;
	}
	else
	{
		g_data->x = 0;
		if (g_data->b_env == 0)
		{
			while (g_data->cmd_paths[g_data->x])
			{
				free(g_data->cmd_paths[g_data->x]);
				g_data->x++;
			}
			free(g_data->cmd_paths);
		}
	}
}

/**
 * The function frees all allocated memory in a linked list of command 
 * structures.
 */
void	ft_free_all(t_data *g_data, int argc)
{
	ft_backward_node(g_data);
	g_data->i = 2;
	if (g_data->b_here_doc == 1)
		g_data->i = 3;
	while (g_data->i < argc - 1)
	{
		g_data->x = 0;
		ft_free_matrix(g_data, 0);
		if (g_data->cmd_lst->next != NULL)
			g_data->cmd_lst = g_data->cmd_lst->next;
		g_data->i++;
	}
	ft_free_matrix(g_data, 1);
	ft_backward_node(g_data);
	while (g_data->cmd_lst)
		ft_deletenod(g_data);
	free(g_data);
}

void	ft_error(int err)
{
	if (err == 0)
	{
		perror("incorrect number of argument");
		exit(1);
	}
	if (err == 1)
		perror("incorrect infile");
	if (err == 2)
	{
		perror("incorrect outfile");
		exit(0);
	}
	if (err == 3)
	{
		perror("command not found");
		exit(0);
	}
	if (err == 4)
	{
		perror("failed to execute");
		exit(0);
	}
}
