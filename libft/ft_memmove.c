/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:37:05 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/21 00:16:51 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n >= 1)
		{
			((char*)dest)[n - 1] = ((char*)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
