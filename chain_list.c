#include "ft_ls.h"

// declare t_file struct
// typedef struct s_file
// {
//     char *name;
//     struct s_file *next;
// } t_file;

// create all functions for chained list
t_file *create_file(char *name, char *path)
{
    t_file *new;

    new = (t_file *)malloc(sizeof(t_file));
    new->name = ft_strdup(name);
    new->path = ft_strdup(path);
    new->next = NULL;
    return (new);
}

void add_file(t_file **head, char *name, char *path)
{
    t_file *new;
    t_file *tmp;

    new = create_file(name, path);
    if (!*head)
    {
        *head = new;
        return ;
    }
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void print_files(t_file *head)
{
    t_file *tmp;

    tmp = head;
    while (tmp)
    {
        ft_printf("%s ", tmp->path);
        tmp = tmp->next;
    }
}


