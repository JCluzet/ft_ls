/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 09:20:20 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:11:00 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_inc/ft_printf.h"

int		pourcenception(char *str, va_list args, t_pf *pf)
{
	if (str[pf->index] == 'c')
		return (type_c(args, pf));
	else if (str[pf->index] == 's')
		return (type_s(args, pf));
	else if (str[pf->index] == 'd' || str[pf->index] == 'i')
		return (type_d(args, pf));
	else if (str[pf->index] == 'u')
		return (type_u(args, pf));
	else if (str[pf->index] == 'x')
		return (type_x(args, pf));
	else if (str[pf->index] == 'X')
		return (type_xmaj(args, pf));
	else if (str[pf->index] == 'p')
		return (type_p(args, pf));
	else if (str[pf->index] == '%')
		return (type_pourc(pf));
	return (ecrire(str[pf->index - 1], pf) + pf->index - 1);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	char	*str;
	t_pf	pf;

	va_start(args, format);
	str = (char*)format;
	pf.index = 0;
	pf.returndepf = 0;
	while (str[pf.index])
	{
		if (str[pf.index] == '%')
			manip(str, args, &pf);
		else
			pf.index += ecrire(str[pf.index], &pf);
	}
	va_end(args);
	return (pf.returndepf);
}

void	manip(char *str, va_list args, t_pf *pf)
{
	initflag(pf);
	pf->index++;
	if (str[pf->index] == '0')
	{
		pf->boleen_flag_0 = 1;
		pf->index++;
	}
	if ((str[pf->index] <= '9' && str[pf->index] >= '0')
			|| str[pf->index] == '+' || str[pf->index] == '-')
		pf->nombre_largeur = ft_atoi(&str[pf->index], pf, 1);
	if (str[pf->index] == '*')
		pf->nombre_largeur = etoileception(pf, args);
	if (str[pf->index] == '-' || str[pf->index] == '+')
		pf->index = pf->index + 1;
	if (str[pf->index] == '.')
	{
		pf->nombre_precision = ft_atoi(&str[pf->index + 1], pf, 0);
		pf->p_boleen = 1;
	}
	if (str[pf->index] == '*')
		pf->nombre_precision = etoileception2(pf, args);
	pf->index = pourcenception(str, args, pf);
}

void	initflag(t_pf *pf)
{
	pf->boleen_largeur = 2;
	pf->nombre_precision = 0;
	pf->boleen_flag_0 = 0;
	pf->p_boleen = 0;
	pf->nombre_largeur = 0;
}
