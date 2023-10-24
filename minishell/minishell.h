/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:03:58 by rrimonte          #+#    #+#             */
/*   Updated: 2023/10/16 19:29:25 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct t_l_data
{
	struct t_l_data		*previous;
	struct t_l_data		*next;
	char				*cmd;
	int					tag;
	int					fd[2];
}	t_data_list;

typedef struct t_g_data
{
	struct t_l_data		*cmd_lst;
}	t_g_data;

void	inicialize_list(t_g_data *g_data);
void	ft_backward_node(t_g_data *g_data);
void	ft_forward_node(t_g_data *g_data);

#endif
