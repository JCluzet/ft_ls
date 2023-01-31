/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:37:05 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/20 21:33:53 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		u;
	char	*tmp;

	i = 0;
	u = -1;
	tmp = (char*)s;
	while (tmp[i])
	{
		if (c == tmp[i])
			u = i;
		i++;
	}
	if (tmp[i] == '\0' && c == '\0')
		return (tmp + i);
	if (u != -1)
		return (tmp + u);
	return (NULL);
}
