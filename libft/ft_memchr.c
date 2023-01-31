/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:37:05 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/20 21:23:19 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == s1[i])
			return (s1 + i);
		i++;
	}
	return (0);
}
