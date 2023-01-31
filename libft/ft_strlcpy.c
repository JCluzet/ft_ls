/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:00:00 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/29 19:54:46 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while ((src[i]) && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		i = 0;
	}
	while (src[i])
		i++;
	return (i);
}
