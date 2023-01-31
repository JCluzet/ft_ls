/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:37:05 by jcluzet           #+#    #+#             */
/*   Updated: 2019/12/04 00:24:04 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s2[i])
	{
		if ((s1[i] != s2[i]) || i >= n)
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0]
				&& find(haystack + i + 1, needle + 1, len - i - 1))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
