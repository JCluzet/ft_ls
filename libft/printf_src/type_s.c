/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 13:02:27 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:16:18 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_inc/ft_printf.h"


int		type_s(va_list args, t_pf *pf)
{
	int		index;
	char	*args_s;

	index = 0;
	args_s = va_arg(args, char*);
	initialisationflag(pf);
	if (args_s == NULL)
		args_s = "(null)";
	if ((ft_strlen(args_s) > pf->nombre_precision) && pf->p_boleen)
		pf->lenght_s = pf->nombre_precision;
	else
		pf->lenght_s = ft_strlen(args_s);
	if (!(pf->boleen_largeur))
		showlargeurs(pf);
	while (index < pf->lenght_s)
	{
		ecrire(args_s[index], pf);
		index++;
	}
	if (pf->boleen_largeur == 1)
		showlargeurs(pf);
	return (1 + pf->index);
}

int		showlargeurs(t_pf *pf)
{
	int	index;
	int v;

	index = 0;
	if (pf->boleen_largeur == 2)
		v = 0;
	else
		v = (pf->nombre_largeur - pf->lenght_s);
	while (index < v)
	{
		if (pf->boleen_flag_0)
			ecrire('0', pf);
		else
			ecrire(' ', pf);
		index++;
	}
	return (0);
}
