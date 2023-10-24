/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:29:34 by rrimonte          #+#    #+#             */
/*   Updated: 2023/04/17 15:33:25 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pt;
	int		size;
	int		size2;

	if (s1 == 0 || s2 == 0)
		return (0);
	size = ft_strlen(s1);
	size2 = ft_strlen(s2) + 1;
	pt = malloc((size + size2) * sizeof(char));
	if (pt != 0)
	{
		ft_strlcpy(pt, (char *)s1, size + 1);
		ft_strlcpy(pt + size, (char *)s2, size2);
	}
	return (pt);
}
