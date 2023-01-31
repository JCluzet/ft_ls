/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:26:04 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:16:20 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_inc/ft_printf.h"


int		type_u(va_list args, t_pf *pf)
{
	int		d;
	char	c;

	d = va_arg(args, unsigned int);
	initialisationflag(pf);
	c = (pf->boleen_flag_0 && (pf->p_boleen == 0) &&
	pf->boleen_largeur != 1 ? '0' : ' ');
	while (pf->nombre_precision > (ft_putnbr_strlen_u(d) + pf->d_num_zero))
		pf->d_num_zero++;
	pf->d_numberof0 = pf->d_num_zero + ft_putnbr_strlen_u(d);
	if (!(pf->boleen_largeur))
		showlargeuru(pf, d, c);
	affichonsu(d, pf);
	if (pf->boleen_largeur == 1)
		showlargeuru(pf, d, c);
	return (1 + pf->index);
}

int		showlargeuru(t_pf *pf, unsigned int d, char c)
{
	if (pf->p_boleen == 1 && pf->nombre_precision == 0 && d == 0)
		while (pf->nombre_largeur > 0)
		{
			ecrire(c, pf);
			pf->nombre_largeur--;
		}
	while (pf->nombre_largeur > pf->d_numberof0)
	{
		ecrire(c, pf);
		pf->d_numberof0++;
	}
	return (0);
}

void	affichonsu(unsigned int d, t_pf *pf)
{
	while (pf->d_num_zero > pf->index_d)
	{
		ecrire('0', pf);
		pf->index_d++;
	}
	if (!(d == 0 && pf->nombre_precision == 0 && pf->p_boleen == 1))
		ft_putnbr_u(d, pf);
}

void	ft_putnbr_u(unsigned int nb, t_pf *pf)
{
	unsigned int i;

	i = 1;
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

int		ft_putnbr_strlen_u(unsigned int nb)
{
	unsigned int i;
	unsigned int v;

	v = 0;
	i = 1;
	if (nb == 0)
		return (1);
	while (nb / i >= 10)
		i = i * 10;
	while (i > 0)
	{
		i = i / 10;
		v++;
	}
	return (v);
}
