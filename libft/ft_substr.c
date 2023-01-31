/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:40:17 by jcluzet           #+#    #+#             */
/*   Updated: 2023/01/31 01:56:29 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((tmp = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	while ((i < (int)len) && (int)ft_strlen(s) >= (int)start)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
