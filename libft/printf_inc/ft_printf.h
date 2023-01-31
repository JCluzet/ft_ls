/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 22:21:03 by jocluzet          #+#    #+#             */
/*   Updated: 2023/01/31 02:15:45 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
// # include "printf_src/type_d.c"
// # include "printf_src/type_c.c"


typedef struct	s_pf
{
	int	boleen_largeur;
	int	index;
	int l2;
	int index_d;
	int	nombre_largeur;
	int	returndepf;
	int nombre_precision;
	int p_boleen;
	int	boleen_argc_d;
	int neg_boleen;
	int lenght_s;
	int d_num_zero;
	int	d_numberof0;
	int boleen_flag_0;
}				t_pf;

int				type_c(va_list args, t_pf *pf);
void			ft_putnbr_u(unsigned int nb, t_pf *pf);
int				ft_putnbr_strlen_u(unsigned int nb);
int				type_p(va_list args, t_pf *pf);
void			affichonsd(int d, t_pf *pf);
void			affichonsu(unsigned int d, t_pf *pf);
void			initialisationflag(t_pf *pf);
int				showlargeurs(t_pf *pf);
int				showlargeuru(t_pf *pf, unsigned int d, char c);
int				showlargeurd(t_pf *pf, int d, char c);
int				type_x(va_list args, t_pf *pf);
int				type_u(va_list args, t_pf *pf);
void			ft_putnbr_base_p(unsigned long long nbr, char *base, t_pf *pf);
void			ft_putnbr_base(unsigned int nbr, char *base, t_pf *pf);
int				type_xmaj(va_list args, t_pf *pf);
int				ft_atoi(char *str, t_pf *pf, int p);
int				ft_putnbr_strlen(int nb);
void			manip(char *str, va_list args, t_pf *pf);
int				pourcenception(char *str, va_list args, t_pf *pf);
int				etoileception(t_pf *pf, va_list args);
int				ecrire(char c, t_pf *pf);
int				ft_strlen_pp(long long d);
int				type_s(va_list args, t_pf *pf);
void			ft_putnbr(int nb, t_pf *pf);
int				type_d(va_list args, t_pf *pf);
void			initflag(t_pf *pf);
void			affichonsp(unsigned long long d, t_pf *pf);
int				showlargeurp(t_pf *pf, char c);
int				type_pourc(t_pf *pf);
void			affichonsxmaj(unsigned int d, t_pf *pf);
int				ft_strlen_x(unsigned int d);
void			affichonsx(unsigned int d, t_pf *pf);
int				showlargeurx(t_pf *pf, char c, unsigned int d);
void			largeur_c(int num, t_pf *pf);
int				ft_strlen(char *str);
int				etoileception2(t_pf *pf, va_list args);

#endif
