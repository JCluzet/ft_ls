#include "ft_ls.h"

char *ft_strdup(char *s)
{
    char *moulitruc;
    int i;
    int u;

    i = 0;
    u = (int)ft_strlen(s);
    moulitruc = malloc(sizeof(char) * u + 1);
    if (moulitruc == NULL)
        return (NULL);
    while (s[i])
    {
        moulitruc[i] = s[i];
        i++;
    }
    moulitruc[i] = '\0';
    return (moulitruc);
}

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

char *ft_strrev(char *str)
{
    int i = 0;
    int j = ft_strlen(str) - 1;
    char tmp;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return (str);
}

char *ft_itoa(int n)
{
    char *str;
    int i = 0;
    int sign = 1;
    int len = 0;
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    if (n < 0)
    {
        sign = -1;
        n = -n;
        len++;
    }
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    n = (sign == -1) ? -n : n;
    while (n > 0)
    {
        str[i++] = n % 10 + '0';
        n /= 10;
    }
    if (sign == -1)
        str[i++] = '-';
    str[i] = '\0';
    return (ft_strrev(str));
}

void ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + '0');
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}