/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:40:17 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/29 18:55:55 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;
	int		u;

	u = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	tmp = malloc(sizeof(char) * ((int)ft_strlen(s1) + (int)ft_strlen(s2) + 1));
	if (tmp == NULL)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[u])
		tmp[i++] = s2[u++];
	tmp[i] = '\0';
	return (tmp);
}
