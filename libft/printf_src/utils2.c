/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:34:04 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:16:36 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_inc/ft_printf.h"


void	ft_putnbr_base(unsigned int nbr, char *base, t_pf *pf)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	while (--i >= 0)
		ecrire(base[nbr_final[i]], pf);
}

void	ft_putnbr_base_p(unsigned long long nbr, char *base, t_pf *pf)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	while (--i >= 0)
		ecrire(base[nbr_final[i]], pf);
}

int		etoileception(t_pf *pf, va_list args)
{
	int	d;

	d = va_arg(args, int);
	if (d < 0)
	{
		d = d * -1;
		if (pf->boleen_largeur == 2)
			pf->boleen_largeur = 1;
	}
	if (pf->boleen_largeur == 2)
		pf->boleen_largeur = 0;
	pf->index++;
	return (d);
}

int		etoileception2(t_pf *pf, va_list args)
{
	int	d;

	d = va_arg(args, int);
	if (d < 0)
	{
		d = 0;
		pf->p_boleen = 0;
	}
	pf->index++;
	return (d);
}

void	initialisationflag(t_pf *pf)
{
	pf->d_numberof0 = 0;
	pf->index_d = 0;
	pf->neg_boleen = 0;
	pf->d_num_zero = 0;
	pf->l2 = 0;
}
