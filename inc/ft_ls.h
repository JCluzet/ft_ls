#ifndef FT_LS_H
#define FT_LS_H

#include <stdarg.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

#define BLUE "\033[1;36m"
#if defined(__APPLE__) || defined(__MACH__)
#define RED "\033[0;31m"
#else
#define RED "\033[1;32m"
#endif
#define RESET "\033[0m"
#define VIOLET "\033[0;35m"

typedef struct node
{
    char *path;
    char *name;
    bool isDir;
    bool visited;
    bool exist;
    char options[6];
    struct node *next;
} node;

void display_files(node *head);
void display_directories(node *head, bool show_name, bool long_listing);
void treat_files(node *head);
node *find_folder(char *path, char options[6]);
bool is_executable(char *path);
node *sort_files(node *head);
node *parsing(char **argv, int argc);
void show_parsing(node *head);
int cmp_time(node *first, node *second);
void add_node(node **head, node *new);
int ft_printf(const char *format, ...);
bool is_dir(char *file);
void display_not_found(node *head);
char *ft_strjoin(char *s1, char *s2);
bool path_exists(char *path);
void recursive_option(node *head);

// UTILS FUNCTIONS
int ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);
char *ft_strchr(const char *s, int c);
void ft_putnbr(int n);
void ft_putchar(char c);
int ft_strlen(const char *str);
char *ft_itoa(int n);
char *ft_strrev(char *str);
char *ft_strdup(const char *s);
bool is_in(char *str, char c);
void free_node(node *head);

#endif