/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 22:09:37 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:15:58 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_inc/ft_printf.h"

int		type_c(va_list args, t_pf *pf)
{
	int	c;

	c = va_arg(args, int);
	if (pf->boleen_largeur == 0)
		largeur_c(pf->nombre_largeur - 1, pf);
	write(1, &c, 1);
	if (pf->boleen_largeur == 1)
		largeur_c(pf->nombre_largeur - 1, pf);
	pf->returndepf++;
	return (1 + pf->index);
}

void	largeur_c(int num, t_pf *pf)
{
	int		v;
	char	c;

	v = 0;
	c = (pf->boleen_flag_0 && (pf->p_boleen == 0) &&
			pf->boleen_largeur != 1 ? '0' : ' ');
	while (num > v)
	{
		ecrire(c, pf);
		v++;
	}
}
