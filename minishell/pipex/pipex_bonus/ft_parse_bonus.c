/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:08:21 by rrimonte          #+#    #+#             */
/*   Updated: 2023/10/16 19:24:27 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * The function parses the command line arguments, initializes a list, splits
 * the command, sets the arguments.
 */
void	ft_parse(t_g_data *g_data, int argc, char **argv)
{
	g_data->i = 2;
	if (g_data->b_here_doc == 1)
		g_data->i = 3;
	while (g_data->i < argc - 1)
	{
		inicialize_list(g_data);
		g_data->cmd_lst->cmd = ft_split(argv[g_data->i], ' ');
		g_data->i++;
	}
	g_data->i = 1;
	if (g_data->b_here_doc == 1)
		g_data->i = 2;
}
