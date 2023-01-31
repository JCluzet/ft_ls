/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:23:06 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:16:10 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_inc/ft_printf.h"


int		type_d(va_list args, t_pf *pf)
{
	int		d;
	char	c;

	d = va_arg(args, int);
	initialisationflag(pf);
	if (d < 0)
		pf->neg_boleen = 1;
	c = (pf->boleen_flag_0 && (pf->p_boleen == 0) &&
	pf->boleen_largeur != 1 ? '0' : ' ');
	while (pf->nombre_precision + pf->neg_boleen >
	(ft_putnbr_strlen(d) + pf->d_num_zero))
		pf->d_num_zero++;
	pf->d_numberof0 = pf->d_num_zero + ft_putnbr_strlen(d);
	if (pf->neg_boleen == 1 && c == '0')
		ecrire('-', pf);
	if (!(pf->boleen_largeur))
		showlargeurd(pf, d, c);
	if (pf->neg_boleen == 1 && c == ' ')
		ecrire('-', pf);
	affichonsd(d, pf);
	if (pf->boleen_largeur == 1)
		showlargeurd(pf, d, c);
	return (1 + pf->index);
}

int		showlargeurd(t_pf *pf, int d, char c)
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

void	affichonsd(int d, t_pf *pf)
{
	while (pf->d_num_zero > pf->index_d)
	{
		ecrire('0', pf);
		pf->index_d++;
	}
	if (d < 0 && d != -2147483648)
		d = d * -1;
	if (d == -2147483648)
	{
		write(1, "2147483648", 10);
		pf->returndepf = pf->returndepf + 10;
	}
	else
		ft_putnbr(d, pf);
}
