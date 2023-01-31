/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:37:05 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/20 21:33:00 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	while (tmp[i])
	{
		if (c == tmp[i])
			return (tmp + i);
		i++;
	}
	if (tmp[i] == '\0' && c == '\0')
		return (tmp + i);
	return (NULL);
}
