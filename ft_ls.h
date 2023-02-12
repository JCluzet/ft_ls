#ifndef FT_LS_H
#define FT_LS_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
//include for stat
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

void parse_options(int argc, char **argv, char ***files, bool *options);
int ft_printf(const char *format, ...);
bool is_directory(char *file);
int display_not_found(char **files);
char **get_files(char *files);
void show_files(char **files, bool *options);
int display_system(char **files, bool *options, bool display);

// UTILS FUNCTIONS
int ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);
void ft_putnbr(int n);
void ft_putchar(char c);
int ft_strlen(char *str);
char *ft_itoa(int n);
char *ft_strrev(char *str);
char *ft_strdup(char *s);

#endif