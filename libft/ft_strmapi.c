/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:40:17 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/20 21:43:10 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((tmp = malloc(sizeof(char) * (int)ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		tmp[i] = (*f)(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
