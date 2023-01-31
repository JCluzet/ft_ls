/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:37:05 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/21 00:01:54 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = (char*)src;
	while (i < n)
	{
		((char*)dest)[i] = s1[i];
		if ((char)c == s1[i])
		{
			i++;
			return (dest + i);
		}
		i++;
	}
	return (NULL);
}
