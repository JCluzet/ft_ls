/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:34:05 by jcluzet           #+#    #+#             */
/*   Updated: 2019/12/06 15:51:04 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t sizemax)
{
	size_t	i;

	i = 0;
	while (str[i] && i < sizemax)
		i++;
	return (i);
}

size_t			ft_strlcat(char *dest, char const *src, size_t nb)
{
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strnlen(dest, nb);
	if (lendst == nb)
		return (lensrc + nb);
	if (lensrc < nb - lendst)
		ft_memcpy(dest + lendst, src, lensrc + 1);
	else
	{
		ft_memcpy(dest + lendst, src, nb - lendst - 1);
		dest[lendst + nb - lendst - 1] = '\0';
	}
	return (lensrc + lendst);
}
