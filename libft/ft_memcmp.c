/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:37:05 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/20 21:24:45 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *poi1;
	const unsigned char *poi2;
	size_t				i;

	poi1 = (const unsigned char *)s1;
	poi2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (poi1[i] != poi2[i])
			return (poi1[i] - poi2[i]);
		i++;
	}
	return (0);
}
