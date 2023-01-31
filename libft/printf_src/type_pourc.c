/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pourc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:59:57 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:16:15 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_inc/ft_printf.h"


int	type_pourc(t_pf *pf)
{
	if (pf->boleen_largeur == 0)
		largeur_c(pf->nombre_largeur - 1, pf);
	ecrire('%', pf);
	if (pf->boleen_largeur == 1)
		largeur_c(pf->nombre_largeur - 1, pf);
	return (1 + pf->index);
}
