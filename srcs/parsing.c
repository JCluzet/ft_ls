#include "../inc/ft_ls.h"

void add_node(node **head, node *new)
{
    node *tmp = *head;

    if (*head == NULL)
        *head = new;
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

node *parsing(char **argv, int argc)
{
    node *head = NULL;
    node *current = NULL;
    node *previous = NULL;
    char options[6] = {0};
    int i = 1;
    int index_options = 0;

    while (i < argc)
    {
        if (argv[i][0] != '-')
            break;
        else
        {
            for (int j = 1; argv[i][j] != '\0'; j++)
            {
                if (is_in(options, argv[i][j]))
                {
                    ft_printf("-%c Already in options\n", argv[i][j]);
                    continue;
                }
                else if (argv[i][j] != 'l' && argv[i][j] != 'R' && argv[i][j] != 'a' && argv[i][j] != 'r' && argv[i][j] != 't')
                {
                    ft_printf("ls: illegal option -- %c\n", argv[i][j]);
                    ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n");
                    exit(2);
                }
                else
                {
                    options[index_options] = argv[i][j];
                    index_options++;
                    options[index_options] = '\0';
                }
            }
        }
        i++;
    }

    if (i == argc)
    {
        current = (node *)malloc(sizeof(node));
        if (current == NULL)
            return (NULL);
        current->path = ft_strdup(".");
        current->name = ft_strdup(".");
        current->visited = false;
        current->isDir = true;
        int j = 0;
        for (; options[j] != '\0'; j++)
            current->options[j] = options[j];
        current->options[j] = '\0';
        current->next = NULL;
        head = current;
        return (head);
    }

    while (i < argc)
    {
        current = (node *)malloc(sizeof(node));
        if (current == NULL)
            return (NULL);
        current->path = ft_strdup(argv[i]);
        current->name = ft_strdup(argv[i]);
        current->visited = false;
        current->isDir = false;
        int j = 0;
        for (; options[j] != '\0'; j++)
            current->options[j] = options[j];
        current->options[j] = '\0';
        current->next = NULL;
        if (head == NULL)
            head = current;
        else
            previous->next = current;
        previous = current;
        i++;
    }
    return (head);
}

void show_parsing(node *head)
{
    node *tmp = head;
    ft_printf("Options: %s\n\n", tmp->options);
    while (tmp)
    {
        ft_printf("Path: %s\n", tmp->path);
        ft_printf("Name: %s\n", tmp->name);
        ft_printf("Exist: %d\n", tmp->exist);
        ft_printf("IsDir: %d\n", tmp->isDir);
        ft_printf("IsScan: %d\n\n", tmp->visited);
        tmp = tmp->next;
    }
    ft_printf("=======\n");
}