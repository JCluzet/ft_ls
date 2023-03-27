#include <stdio.h>
#include <stdlib.h>
#include "ft_ls.h"
#include <stdbool.h>
#include <string.h>

// fill details about files
void treat_files(node *head)
{
    node *tmp = head;
    while (tmp)
    {
        if (path_exists(tmp->path))
        {
            tmp->exist = true;
            if (is_dir(tmp->path))
                tmp->isDir = true;
            else
                tmp->isDir = false;
        }
        else
            tmp->exist = false;
        tmp = tmp->next;
    }
}

// remove useless files (files that don't exist or are not directories)
node *remove_useless_files(node *head)
{
    node *tmp = NULL;
    node *tofree = head;

    while (head)
    {
        if (head->exist && head->isDir)
        {
            if (tmp == NULL)
            {
                tmp = (node *)malloc(sizeof(node));
                tmp->path = ft_strdup(head->path);
                tmp->name = ft_strdup(head->name);
                tmp->isDir = head->isDir;
                for (int i = 0; i < 6; i++)
                    tmp->options[i] = head->options[i];
                tmp->exist = head->exist;
                tmp->next = NULL;
            }
            else
            {
                node *current = tmp;
                while (current->next)
                    current = current->next;
                current->next = (node *)malloc(sizeof(node));
                current->next->path = ft_strdup(head->path);
                current->next->name = ft_strdup(head->name);
                for (int i = 0; i < 6; i++)
                    current->next->options[i] = head->options[i];
                current->next->isDir = head->isDir;
                current->next->exist = head->exist;
                current->next->next = NULL;
            }
        }
        head = head->next;
    }
    free_node(tofree);
    return (tmp);
}

// return all folder/files find in the path
node *find_folder(char *path, char options[6])
{
    node *head = NULL;
    node *current = NULL;
    node *previous = NULL;
    DIR *dir;
    struct dirent *sd;
    dir = opendir(path);
    if (dir == NULL)
        return NULL;
    while ((sd = readdir(dir)) != NULL)
    {
        if (sd->d_name[0] != '.' || is_in(options, 'a'))
        {
            current = (node *)malloc(sizeof(node));
            current->path = ft_strjoin(path, "/");
            char *tmp_path = current->path;
            current->path = ft_strjoin(tmp_path, sd->d_name);
            free(tmp_path);
            current->name = ft_strdup(sd->d_name);
            current->isDir = is_dir(current->path);
            current->is_scan = false;
            current->visited = false;
            current->exist = 1;
            for (int i = 0; i < 6; i++)
                current->options[i] = options[i];
            current->next = NULL;
            if (head == NULL)
                head = current;
            else
                previous->next = current;
            previous = current;
        }
    }
    head = sort_files(head);
    // print how many files are found
    closedir(dir);
    return (head);
}

void recursive_option(node *head)
{
    node *tmp = head;
    char *path = NULL;
    node *last_node = NULL;

    while (tmp && tmp->visited)
        tmp = tmp->next;
    if (!tmp)
        return;
    last_node = tmp;
    last_node->visited = true;

    node *files = find_folder(last_node->path, last_node->options);
    last_node->is_scan = true;
    node *iter = files;

    while (iter)
    {
        // ft_printf("go to ");
        if (iter->isDir && ft_strcmp(iter->name, ".") != 0 && ft_strcmp(iter->name, "..") != 0)
        {
            node *new_node = (node *)malloc(sizeof(node));
            new_node->path = ft_strdup(iter->path);
            new_node->name = ft_strdup(iter->name);
            // free(iter->path);
            // free(iter->name);
            new_node->isDir = iter->isDir;
            new_node->exist = iter->exist;
            new_node->visited = false;
            new_node->is_scan = false;
            for (int i = 0; i < 6; i++)
                new_node->options[i] = iter->options[i];
            new_node->next = NULL;

            // Find the last node in the list
            node *list_tail = head;
            while (list_tail->next)
            {
                list_tail = list_tail->next;
            }
            list_tail->next = new_node;
            // free(iter);
            // if the folder name is . or .. go to next folder in the list and break
            // ft_printf("\n>>%s\n", iter->name);
            recursive_option(head);
        }
        iter = iter->next;
    }
    free_node(files);
}


int main(int argc, char *argv[])
{
    node *head = NULL;

    // parsing
    head = parsing(argv, argc);

    // fill isDir and exist fields for each file
    treat_files(head);

    // sort files by name, reverse and time
    head = sort_files(head);

    // 1. display not exist files
    display_not_found(head);

    // debug: show parsing

    // 2. display files
    display_files(head);

    // if there is at least one file exist in the list
    bool there_is_files = false;
    bool there_is_directories = false;
    for (node *tmp = head; tmp; tmp = tmp->next)
    {
        if (tmp->exist && tmp->isDir)
        {
            there_is_directories = true;
        }
        if (tmp->exist && !tmp->isDir)
        {
            there_is_files = true;
        }
    }
    if (there_is_files)
        ft_printf("\n");
    if (there_is_files && there_is_directories)
        ft_printf("\n");

    bool linux_os = false;
    #if defined(__APPLE__) || defined(__MACH__)
    linux_os = false;
    #else
    linux_os = true;
    #endif

    // 3. display directories

    // remove all useless files
    head = remove_useless_files(head);
    if (head == NULL)
        return (0);

    bool show_name = false;

    if (there_is_directories && there_is_files)
        show_name = true;

    if (head->next)
        show_name = true;
    
    if(is_in(head->options, 'R') && linux_os)
        show_name = true;

    node *tmp = NULL;
    node *start = NULL;
    node *to_free = head;
    node *files = NULL;

    if (head)
    {
        tmp = (node *)malloc(sizeof(node));
        tmp->path = ft_strdup(head->path);
        tmp->name = ft_strdup(head->name);
        tmp->isDir = head->isDir;
        tmp->exist = head->exist;
        tmp->visited = false;
        tmp->is_scan = false;
        for (int i = 0; i < 6; i++)
            tmp->options[i] = head->options[i];
        tmp->next = NULL;
        start = tmp;
        head = head->next;
        if (is_in(tmp->options, 'R'))
            recursive_option(tmp);
    }

    while (head)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->path = ft_strdup(head->path);
        new_node->name = ft_strdup(head->name);
        new_node->isDir = head->isDir;
        new_node->visited = false;
        new_node->exist = head->exist;
        new_node->is_scan = false;
        for (int i = 0; i < 6; i++)
            new_node->options[i] = head->options[i];
        new_node->next = NULL;

        tmp = start;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;

        if (is_in(new_node->options, 'R'))
            recursive_option(new_node);

        head = head->next;
    }
    if(files)
        free_node(files);
    

    display_directories(start, show_name, is_in(start->options, 'l'));

    free_node(to_free);
    free_node(start);
    return (0);
}