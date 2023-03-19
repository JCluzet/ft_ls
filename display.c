#include "ft_ls.h"

void display_directories(node *head, bool show_name)
{
    node *tmp = head;
    int i = 0;
    bool folder_exist = false;
    while (tmp)
    {
        if (tmp->exist && tmp->isDir)
        {
            if (show_name)
                ft_printf("%s:\n", tmp->path);
            else if (i > 0)
                ft_printf("%s:\n", tmp->path);

            node *folder = find_folder(tmp->path, tmp->options);

            folder = sort_files(folder);
            folder_exist = folder;

            while (folder)
            {
                if (folder->isDir)
                    ft_printf("%s", BLUE);
                else if (is_executable(folder->path))
                    ft_printf("%s", RED);
                ft_printf("%s ", folder->name);
                ft_printf("%s", RESET);
                folder = folder->next;
            }
            if (folder_exist)
                ft_printf("\n");
            if (tmp->next)
                ft_printf("\n");
        }
        tmp = tmp->next;
        i++;
    }
}


void display_files(node *head)
{
    node *tmp = head;
    while (tmp)
    {
        if (tmp->exist && !tmp->isDir)
            ft_printf("%s ", tmp->name);
        tmp = tmp->next;
    }
}

void display_not_found(node *head)
{
    node *tmp = head;
    while (tmp)
    {
        if (!tmp->exist)
            ft_printf("ls: %s: No such file or directory\n", tmp->name);
        tmp = tmp->next;
    }
}