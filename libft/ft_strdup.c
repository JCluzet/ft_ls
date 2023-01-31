/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:40:17 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/20 21:29:58 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*moulitruc;
	int		i;
	int		u;

	i = 0;
	u = (int)ft_strlen(s);
	moulitruc = malloc(sizeof(char) * u + 1);
	if (moulitruc == NULL)
		return (NULL);
	while (s[i])
	{
		moulitruc[i] = s[i];
		i++;
	}
	moulitruc[i] = '\0';
	return (moulitruc);
}
