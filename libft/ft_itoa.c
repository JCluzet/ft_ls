/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:47:25 by jcluzet           #+#    #+#             */
/*   Updated: 2019/12/01 05:20:27 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlendeint(int n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

static char		*reverse(char *str)
{
	int		i;
	int		u;
	char	chara;

	i = 0;
	u = (int)ft_strlen(str) - 1;
	while (i < ((int)(ft_strlen(str)) / 2))
	{
		chara = str[i];
		str[i] = str[u];
		str[u] = chara;
		i++;
		u--;
	}
	return (str);
}

char			*ft_itoa(int nbr)
{
	char	*tmp;
	int		interm;
	int		neg;
	int		i;

	i = 0;
	neg = 0;
	if (nbr < 0)
		neg = 1;
	if ((tmp = malloc(sizeof(char) * ft_strlendeint(nbr))) == NULL)
		return (NULL);
	if (nbr == 0)
		tmp[i++] = '0';
	while (nbr != 0)
	{
		interm = nbr % 10;
		if (interm < 0)
			interm = interm * -1;
		tmp[i++] = interm + 48;
		nbr = nbr / 10;
	}
	if (neg)
		tmp[i++] = '-';
	tmp[i] = '\0';
	return (reverse(tmp));
}
