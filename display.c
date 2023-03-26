#include "ft_ls.h"

#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

void file_mode_string(mode_t mode, char *str)
{
    const char *chars = "rwxrwxrwx";
    for (int i = 0; i < 9; ++i)
    {
        str[i] = (mode & (1 << (8 - i))) ? chars[i] : '-';
    }
    str[9] = '\0';
}

int ft_numlonglen(unsigned long long n)
{
    int len = 0;

    if (n == 0)
        return (1);
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char ft_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

void display_file_details(const char *path, const struct stat *file_stat)
{
    char file_mode[11];
    file_mode_string(file_stat->st_mode, file_mode);
    file_mode[10] = '\0';
    if (S_ISDIR(file_stat->st_mode))
        ft_printf("d");
    else
        ft_printf("-");
    ft_printf("%s ", file_mode);
    int space = 4 - ft_numlonglen(file_stat->st_nlink);
    while (space-- && space > 0)
        ft_printf(" ");
    ft_printf("%ld ", (unsigned long)file_stat->st_nlink);
    ft_printf("%s %s ", getpwuid(file_stat->st_uid)->pw_name, getgrgid(file_stat->st_gid)->gr_name);
   
    space = 9 - ft_numlonglen(file_stat->st_size);

    while (space-- && space > 0)
        ft_printf(" ");
    ft_printf("%ld ", (long long)file_stat->st_size);
    char time_str[20];
#if defined(__APPLE__) || defined(__MACH__)
    strftime(time_str, sizeof(time_str), "%d", localtime(&file_stat->st_mtime));
    ft_printf("%s ", time_str);
    strftime(time_str, sizeof(time_str), "%b", localtime(&file_stat->st_mtime));
    // put in minuscule the month
    for (int i = 0; time_str[i]; i++)
        time_str[i] = ft_tolower(time_str[i]);
#else
    strftime(time_str, sizeof(time_str), "%b %d", localtime(&file_stat->st_mtime));
#endif

    ft_printf("%s ", time_str);
    strftime(time_str, sizeof(time_str), "%H:%M", localtime(&file_stat->st_mtime));
    ft_printf("%s ", time_str);
}

void free_list(node *head)
{
    node *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->path);
        free(tmp->name);
        free(tmp);
    }
}

void display_directories(node *head, bool show_name, bool long_listing)
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
            node *temp_free = folder;
            folder_exist = folder != NULL;

            // Calculate the total number of blocks used by the files in the directory
            unsigned long total_blocks = 0;
            node *folder_iter = folder;
            while (folder_iter)
            {
                struct stat file_stat;
                if (lstat(folder_iter->path, &file_stat) == 0)
                {
                    total_blocks += file_stat.st_blocks;
                }
                folder_iter = folder_iter->next;
            }

            // Display the total
            if (long_listing)
            {
                if (total_blocks == 0)
                    ft_printf("total 0\n");
                else
                    ft_printf("total %ld\n", total_blocks);
            }

            // Display the directory content
            while (folder)
            {
                if (long_listing)
                {
                    struct stat file_stat;
                    if (lstat(folder->path, &file_stat) == 0)
                    {
                        display_file_details(folder->path, &file_stat);
                    }
                }

                if (folder->isDir)
                    ft_printf("%s", BLUE);
                else if (is_executable(folder->path))
                    ft_printf("%s", RED);
                ft_printf("%s", folder->name);
                ft_printf("%s", RESET);

                if (long_listing)
                    ft_printf("\n");
                else
                    ft_printf(" ");

                folder = folder->next;
            }
            if (folder_exist && !long_listing)
                ft_printf("\n");
            if (tmp->next)
                ft_printf("\n");
            free_list(temp_free);
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