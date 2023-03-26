#include "ft_ls.h"

int ft_numlen(unsigned long long n)
{
    int len = 0;

    if (n == 0)
        return (1);
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}
char *ft_ultoa(unsigned long n)
{
    char *str;
    int len = ft_numlen(n);

    if (!(str = (char *)malloc(len + 1)))
        return (NULL);
    str[len] = '\0';
    while (len--)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}



char *ft_lltoa(long long n)
{
    char *str;
    long long len = ft_numlen(n < 0 ? -n : n);
    int neg = n < 0;

    if (neg)
        len++;
    if (!(str = (char *)malloc(len + 1)))
        return (NULL);
    str[len] = '\0';
    while (len--)
    {
        str[len] = '0' + (n % 10 < 0 ? -(n % 10) : n % 10);
        n /= 10;
    }
    if (neg)
        str[0] = '-';
    return (str);
}


int ft_printf(const char *format, ...)
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
            else if (format[i] == 'u')
            {
                unsigned long lu = va_arg(args, unsigned long);
                char *ustr = ft_ultoa(lu);
                ft_putstr(ustr);
                ret += ft_strlen(ustr);
                free(ustr);
            }
            else if (format[i] == 'l')
            {
                i++;
                if (format[i] == 'd')
                {
                    long long lld = va_arg(args, long long);
                    char *lldstr = ft_lltoa(lld);
                    ft_putstr(lldstr);
                    ret += ft_strlen(lldstr);
                    free(lldstr);
                }
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

