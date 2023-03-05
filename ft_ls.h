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

#define BLUE "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"


// create a chained list to store the files
typedef struct s_file
{
    char *name;
    char* path;
    struct s_file *next;
} t_file;

void add_file(t_file **head, char *name, char *path);
// create a chained list to store the directories
typedef struct s_dir
{
    char *name;
    struct s_dir *next;
} t_dir;

void print_files(t_file *head);
bool is_executable(char *path);

void parse_options(int argc, char **argv, char ***files, bool *options);
int ft_printf(const char *format, ...);
bool is_directory(char *file);
int display_not_found(char **files);
char **chain_list_to_array(t_file *head);
char **get_files(char *files);
char *ft_strjoin(char *s1, char *s2);
void show_files(char **files, bool *options, char *path);
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