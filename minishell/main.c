/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:00:05 by rrimonte          #+#    #+#             */
/*   Updated: 2023/10/16 19:08:27 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "pipex/libft/libft.h"
#include "minishell.h"

// Función  para dividir una cadena en comandos y flags
void	splitcommands(const char *input, t_g_data *g_data)
{
	const char	delimiters[] = "<|>;";
	const char	*start;
	const char	*end;
	int			bcomillas;
	int			bspaces;

	start = input;
	end = 0;
	bcomillas = 0;
	while (*start != '\0' && *start != ';')
	{
		inicialize_list(g_data);
		// Saltar los delimitadores iniciales
		while (*start != '\0' && ft_strchr(delimiters, *start) != NULL)
		{
			if (*start == '"')
			{
				if (bcomillas == 0)
					bcomillas = 1;
				else
					bcomillas = 0;
			}
			if (*start == '<' && bcomillas == 0)
			{
				g_data->cmd_lst->tag = 1;
				start++;
				if (*start == '<')
					g_data->cmd_lst->tag = 5;
				printf("tag--->|%d|\n", g_data->cmd_lst->tag);
			}
			start++;
		}
		while (*start == ' ')
			start++;
		// Encontrar el final del comando
		end = start;
		bspaces = 0;
		if (g_data->cmd_lst->tag == 1 || g_data->cmd_lst->tag == 5)
		{
			while (*end != '\0' && ft_strchr(" ", *end) == NULL)
				end++;
		}
		else
		{
			while (*end != '\0' && ft_strchr(delimiters, *end) == NULL)
			{
				bspaces++;
				if (*end != ' ' && ft_strchr(delimiters, *end) == NULL)
				{
					bspaces = 0;
				}
				if (*end == '"')
				{
					if (bcomillas == 0)
						bcomillas = 1;
					else
					bcomillas = 0;
				}
				end++;
				if (ft_strchr(delimiters, *end) != NULL && bcomillas == 1)
					end++;
			}
			if (*end == '|')
				g_data->cmd_lst->tag = 2;
			else if (*end == '>')
			{
				end++;
				if (*end == '>')
					g_data->cmd_lst->tag = 4;
				else
					g_data->cmd_lst->tag = 3;
				end--;
			}
			printf("tag--->|%d|\n", g_data->cmd_lst->tag);
		}
		// Construye el comando completo incluyendo flags
		if (*start != '\0')
		{
			g_data->cmd_lst->cmd = (char *)malloc (sizeof(char) * ((end - bspaces) - start + 1));
			ft_strlcpy(g_data->cmd_lst->cmd, start, (end - bspaces) - start + 1);
			printf("|%s|\n", g_data->cmd_lst->cmd);
		}
		start = end;
	}
}

int	main(void)
{
	t_g_data	*g_data;
	char		*input;
	int			i;
	int			nstr;
	const char	delimiters[] = "<|>";

	g_data = malloc(sizeof(t_data_list));
	if (g_data == NULL)
		return (0);
	i = 0;
	nstr = 1;
	input = readline("Ingresa tu mensaje: ");
	while (input[i])
	{
		if (ft_strchr(delimiters, input[i]) != NULL)
			nstr++;
		i++;
	}
	splitcommands(input, g_data);
	printf("comprabando comandos guardados...\n");
	ft_backward_node(g_data);
	ft_forward_node(g_data);
	return (0);
}

void	inicialize_list(t_g_data *g_data)
{
	t_data_list	*temp;
	t_data_list	*aux;

	temp = malloc(sizeof(*temp));
	if (temp == 0)
		return ;
	temp->next = 0;
	temp->previous = 0;
	temp->tag = 0;
	temp->fd[0] = 0;
	temp->fd[1] = 0;
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

void	ft_backward_node(t_g_data *g_data)
{
	while (g_data->cmd_lst != 0 && g_data->cmd_lst->previous != 0)
	{
		g_data->cmd_lst = g_data->cmd_lst->previous;
	}
}

void	ft_forward_node(t_g_data *g_data)
{	
	while (g_data->cmd_lst != 0 && g_data->cmd_lst->next != 0)
	{
		printf("|%s|\n", g_data->cmd_lst->cmd);
		g_data->cmd_lst = g_data->cmd_lst->next;
	}
	printf("|%s|\n", g_data->cmd_lst->cmd);
}

/*
void	ft_deletenod(t_g_data *g_data)
{
	t_data_list	*temp;

	temp = 0;
	if (g_data->cmd_lst->next != 0)
		temp = g_data->cmd_lst->next;
	free (g_data->cmd_lst);
	g_data->cmd_lst = temp;
}
*/