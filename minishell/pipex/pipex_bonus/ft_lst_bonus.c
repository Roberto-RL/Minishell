/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:15:14 by rrimonte          #+#    #+#             */
/*   Updated: 2023/10/16 19:02:32 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * It creates a new node in the linked list and assigns the value of 
 * the number to the node
 */
void	inicialize_list(t_data *g_data)
{
	t_c_list	*temp;
	t_c_list	*aux;

	temp = malloc(sizeof(*temp));
	if (temp == 0)
		return ;
	temp->fd[0] = 0;
	temp->fd[1] = 0;
	temp->next = 0;
	temp->previous = 0;
	if (g_data->cmd_lst == 0)
		g_data->cmd_lst = temp;
	else
	{
		aux = g_data->cmd_lst;
		g_data->cmd_lst->next = temp;
		g_data->cmd_lst = g_data->cmd_lst->next;
		g_data->cmd_lst->previous = aux;
	}
}

void	ft_backward_node(t_data *g_data)
{
	while (g_data->cmd_lst != 0 && g_data->cmd_lst->previous != 0)
		g_data->cmd_lst = g_data->cmd_lst->previous;
}

void	ft_forward_node(t_data *g_data)
{
	while (g_data->cmd_lst != 0 && g_data->cmd_lst->next != 0)
	{
		close(g_data->cmd_lst->fd[READ_O]);
		g_data->cmd_lst = g_data->cmd_lst->next;
	}
}

void	ft_deletenod(t_data *g_data)
{
	t_c_list	*temp;

	temp = 0;
	if (g_data->cmd_lst->next != 0)
		temp = g_data->cmd_lst->next;
	free (g_data->cmd_lst);
	g_data->cmd_lst = temp;
}
