/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:00:00 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/29 19:08:33 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charisset(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int start;
	int u;
	int len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	u = 0;
	while (charisset(s1[u], set) == 1)
		u++;
	if (s1[u] == '\0')
		return (ft_substr(s1, u, 1));
	start = u;
	u = 0;
	while (s1[u])
		u++;
	u--;
	while (charisset(s1[u], set) == 1)
		u--;
	len = u - start + 1;
	return (ft_substr(s1, start, len));
}
