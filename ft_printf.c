/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 09:20:20 by jocluzet          #+#    #+#             */
/*   Updated: 2023/02/02 18:25:32 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i = 0;
    int ret = 0;
    
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                ft_putstr(str);
                ret += ft_strlen(str);
            }
            else if (format[i] == 'd')
            {
                int d = va_arg(args, int);
                ft_putnbr(d);
                ret += ft_strlen(ft_itoa(d));
            }
            else if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                ft_putchar(c);
                ret++;
            }
        }
        else
        {
            ft_putchar(format[i]);
            ret++;
        }
        i++;
    }
    va_end(args);
    return (ret);
}
