#ifndef FT_LS_H
#define FT_LS_H

#include <stdarg.h>
// #include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// include write
#include <unistd.h>

void parse_options(int argc, char **argv, char ***files, bool *options);
int ft_printf(const char *format, ...);

// UTILS FUNCTIONS
void ft_putstr(char *str);
void ft_putnbr(int n);
void ft_putchar(char c);
int ft_strlen(char *str);
char *ft_itoa(int n);
char *ft_strrev(char *str);
char *ft_strdup(char *s);

#endif