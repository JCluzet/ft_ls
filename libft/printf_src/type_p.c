/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:18:11 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:16:14 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_inc/ft_printf.h"


int		type_p(va_list args, t_pf *pf)
{
	unsigned long long	d;
	char				c;

	initialisationflag(pf);
	pf->boleen_argc_d = 0;
	d = va_arg(args, unsigned long long);
	pf->l2 = ((pf->nombre_precision > (ft_strlen_pp(d))) ?
	(pf->nombre_precision - (ft_strlen_pp(d))) : 0);
	pf->d_num_zero = 0;
	ft_strlen_pp(d);
	if (pf->nombre_largeur > pf->l2 + ft_strlen_pp(d) + 2)
		pf->d_num_zero = pf->nombre_largeur - (pf->l2 + ft_strlen_pp(d) + 2);
	c = ' ';
	pf->d_num_zero += (pf->d_num_zero && (pf->p_boleen ||
	pf->nombre_precision) && !d ? 1 : 0);
	if (!pf->boleen_largeur)
		showlargeurp(pf, c);
	ecrire('0', pf);
	ecrire('x', pf);
	affichonsp(d, pf);
	if (pf->boleen_largeur == 1)
		showlargeurp(pf, c);
	return (1 + pf->index);
}

void	affichonsp(unsigned long long d, t_pf *pf)
{
	int index;

	index = 0;
	while (pf->l2 > index)
	{
		ecrire('0', pf);
		index++;
	}
	index = 0;
	if (d)
		ft_putnbr_base_p((unsigned long long)d, "0123456789abcdef", pf);
	else if (!pf->p_boleen || pf->nombre_precision)
		ecrire('0', pf);
}

int		showlargeurp(t_pf *pf, char c)
{
	while (pf->d_num_zero > 0)
	{
		ecrire(c, pf);
		pf->d_num_zero--;
	}
	return (0);
}

int		ft_strlen_pp(long long d)
{
	int len;

	len = 1;
	while (d >= 16)
	{
		d /= 16;
		len++;
	}
	return (len);
}
