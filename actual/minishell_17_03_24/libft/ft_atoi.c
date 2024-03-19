/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:30:49 by rrimonte          #+#    #+#             */
/*   Updated: 2024/03/17 15:10:45 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_check(const char *s, int *z)
{
	if (s[z[0]] != '+' && s[z[0]] != '-' && z[2] == 0)
		if (!(s[z[0]] >= '0' && s[z[0]] <= '9') && z[2] == 0)
			if (ft_strchr(" \t\v\n\r\f", (s[z[0]])) == 0 && z[2] == 0)
				z[5] += 1;
	if (s[z[0]] >= '0' && s[z[0]] <= '9')
	{
		if (z[6] != 0)
			z[1] = z[1] * 10;
		z[1] = z[1] + s[z[0]] - 48;
		z[2] = 1;
		z[6] = 1;
	}
	else if (s[z[0]] == '-')
		z[3] += 1;
	else if (s[z[0]] == '+')
		z[4] += 1;
	else if (ft_strchr(" \t\v\n\r\f", (s[z[0]])) != 0 && (z[3] > 0 || z[4] > 0))
		z[5] += 1;
	if (z[3] > 1 || z[4] > 1 || (z[3] > 0 && z[4] > 0))
		z[5] += 1;
	if (s[z[0]] != '+' && s[z[0]] != '-' && z[2] == 1)
		if (!(s[z[0]] >= '0' && s[z[0]] <= '9') && z[2] == 1)
			z[6] = 0;
	return (z);
}

int	ft_atoi(const char *str)
{
	int	x [7];

	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	x[3] = 0;
	x[4] = 0;
	x[5] = 0;
	x[6] = 0;
	while (str[x[0]] && x[2] != 2)
	{
		*x = *ft_check(str, x);
		if (x[5] > 0 || x[6] == 0)
			return (-1);
		x[0]++;
	}
	if (x[3] % 2 != 0)
		x[1] = x[1] * -1;
	return (x[1]);
}
