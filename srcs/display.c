#include "../inc/ft_ls.h"

void file_mode_string(mode_t mode, char *str)
{
    const char *chars = "rwxrwxrwx";
    for (int i = 0; i < 9; ++i)
    {
        str[i] = (mode & (1 << (8 - i))) ? chars[i] : '-';
    }
    if (mode & S_ISUID)
        str[2] = (mode & S_IXUSR) ? 's' : 'S';
    if (mode & S_ISGID)
        str[5] = (mode & S_IXGRP) ? 's' : 'S';
    if (mode & S_ISVTX)
        str[8] = (mode & S_IXOTH) ? 't' : 'T';
    str[9] = '\0';
}

bool ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}

bool should_quote(const char *folder_name)
{
    for (size_t i = 0; i < strlen(folder_name); ++i)
    {
        if (!ft_isprint(folder_name[i]))
        {
            return true;
        }
        if (folder_name[i] == ' ')
        {
            return true;
        }
        if (folder_name[i] == '!' || folder_name[i] == '$' || folder_name[i] == '&')
        {
            return true;
        }
    }
    return false;
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

void display_file_details(const struct stat *file_stat)
{
    char file_mode[11];
    file_mode_string(file_stat->st_mode, file_mode);
    file_mode[10] = '\0';
    if (S_ISDIR(file_stat->st_mode))
        ft_printf("d");
    else if (S_ISLNK(file_stat->st_mode))
        ft_printf("l");
    else if (S_ISCHR(file_stat->st_mode))
        ft_printf("c");
    else if (S_ISBLK(file_stat->st_mode))
        ft_printf("b");
    else if (S_ISFIFO(file_stat->st_mode))
        ft_printf("p");
    else if (S_ISSOCK(file_stat->st_mode))
        ft_printf("s");
    else
        ft_printf("-");
    ft_printf("%s ", file_mode);
    int space = 4 - ft_numlonglen(file_stat->st_nlink);
    while (space-- && space > 0)
        ft_printf(" ");
    ft_printf("%ld ", (unsigned long)file_stat->st_nlink);
    struct passwd *pw = getpwuid(file_stat->st_uid);
    if (pw == NULL)
    {
        ft_printf("unknown ");
    }
    else
    {
        ft_printf("%s ", pw->pw_name);
    }

    struct group *gr = getgrgid(file_stat->st_gid);
    if (gr == NULL)
    {
        ft_printf("unknown ");
    }
    else
    {
        ft_printf("%s ", gr->gr_name);
    }

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

void display_file(node *file, bool long_listing)
{
    if (long_listing)
    {
        struct stat file_stat;
        if (lstat(file->path, &file_stat) == 0)
        {
            display_file_details(&file_stat);
        }
    }

    struct stat file_stat;
    lstat(file->path, &file_stat);
    if (file->isDir)
        ft_printf("%s", BLUE);
    else if (is_executable(file->path))
        ft_printf("%s", RED);
    else if (S_ISLNK(file_stat.st_mode))
        ft_printf("%s", VIOLET);

    // if the file->name contain a space or special character we need to put it in quotes
    if (should_quote(file->name))
        ft_printf("\'%s\'", file->name);
    else
        ft_printf("%s", file->name);
    ft_printf("%s", RESET);

    // display link if there is one
    if (long_listing)
    {
        if (lstat(file->path, &file_stat) == 0)
        {
            if (S_ISLNK(file_stat.st_mode))
            {
                char link[1024];
                int link_size = readlink(file->path, link, sizeof(link));
                link[link_size] = '\0';
                if (link_size != -1)
                    ft_printf(" -> %s", link);
            }
        }
    }

    if (long_listing)
        ft_printf("\n");
    else
        ft_printf(" ");
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
            // if there is no permission to access the directory we display an error
            if (access(tmp->path, R_OK) != 0 || opendir(tmp->path) == NULL)
            {
                ft_printf("ft_ls: cannot open directory '%s': Permission denied\n", tmp->path);
                tmp = tmp->next;
                continue;
            }
            if (show_name || i > 0)
            {
                if (ft_strchr(tmp->path, ' ') || ft_strchr(tmp->path, '\t'))
                    ft_printf("\'%s\':\n", tmp->path);
                else
                    ft_printf("%s:\n", tmp->path);
            }

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
                if (stat(folder_iter->path, &file_stat) == 0)
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
#if defined(__APPLE__) || defined(__MACH__)
                    ft_printf("total %ld\n", total_blocks);
#else
                    ft_printf("total %ld\n", total_blocks / 2);
#endif
            }

            // Display the directory content
            while (folder)
            {
                display_file(folder, long_listing);
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
            display_file(tmp, is_in(tmp->options, 'l'));
        tmp = tmp->next;
    }
}

void display_not_found(node *head)
{
    node *tmp = head;
    while (tmp)
    {
        if (!tmp->exist)
            ft_printf("ft_ls: %s: No such file or directory\n", tmp->name);
        tmp = tmp->next;
    }
}