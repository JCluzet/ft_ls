/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 22:17:02 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:16:34 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_inc/ft_printf.h"


int		ft_atoi(char *str, t_pf *pf, int p)
{
	int min;
	int nb;

	nb = 0;
	min = 0;
	while (*str == '+' || *str == '-')
	{
		pf->index++;
		if (*str == '-')
			min++;
		str++;
	}
	while (*str && (*str <= '9' && *str >= '0'))
	{
		nb = nb * 10 + (*str - 48);
		str++;
		pf->index++;
	}
	if (p == 1)
		pf->boleen_largeur = ((min % 2 == 0) ? 0 : 1);
	else
		pf->index++;
	return (nb);
}

void	ft_putnbr(int nb, t_pf *pf)
{
	int i;

	i = 1;
	if (!(pf->nombre_precision == 0 && nb == 0 && pf->p_boleen == 1))
	{
		while (nb / i >= 10)
		{
			i = i * 10;
		}
		while (i > 0)
		{
			ecrire((nb / i % 10) + 48, pf);
			i = i / 10;
		}
	}
}

int		ft_putnbr_strlen(int nb)
{
	int i;
	int v;

	v = 0;
	i = 1;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = nb * -1;
		v++;
	}
	while (nb / i >= 10)
		i = i * 10;
	while (i > 0)
	{
		i = i / 10;
		v++;
	}
	return (v);
}

int		ecrire(char c, t_pf *pf)
{
	pf->returndepf++;
	write(1, &c, 1);
	return (1);
}

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
