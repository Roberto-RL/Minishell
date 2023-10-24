/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:40:56 by rrimonte          #+#    #+#             */
/*   Updated: 2022/09/30 11:12:17 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pt;
	int		size;

	size = ft_strlen(s1) + 1;
	pt = malloc(size * sizeof(char));
	if (pt != 0)
		ft_strlcpy(pt, (char *)s1, size);
	return (pt);
}
