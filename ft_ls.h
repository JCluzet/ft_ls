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
#define RED "\033[0;31m"
#define RESET "\033[0m"

typedef struct node
{
    char *path;
    char *name;
    bool isDir;
    bool is_scan;
    bool visited;
    bool exist;
    char options[6];
    struct node *next;
} node;


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
bool is_sorted_time(node *head);
bool is_dir(char *file);
void display_not_found(node *head);
char **chain_list_to_array(t_file *head);
char *ft_strjoin(char *s1, char *s2);
char **sort_by_time(char **files);
bool path_exists(char *path);
node *recursive_option(node *head);
char **reverse_order(char **files);
char **sort_by_alphabetical_order(char **files);

// UTILS FUNCTIONS
int ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);
void ft_putnbr(int n);
void ft_putchar(char c);
int ft_strlen(const char *str);
char *ft_itoa(int n);
char *ft_strrev(char *str);
char *ft_strdup(const char *s);
bool is_in(char *str, char c);
void free_node(node *head);


#endif