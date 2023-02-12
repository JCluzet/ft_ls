#include "ft_ls.h"


int display_not_found(char **files)
{
    // check if each file exists, if not print an error, if yes continue
    int i = 0;
    struct stat st;
    while (files && files[i])
    {
        if (stat(files[i], &st) == -1)
        {
            ft_printf("ls: %s: No such file or directory\n", files[i]);
        }
        i++;
    }
    return (0);
}

int display_system(char **files, bool *options, bool display)
{
    int number_of_files = 0;
    int files_found = 0;
    struct stat st;
    DIR *dir;
    struct dirent *sd;
    int i = 0;
    while (files && files[number_of_files])
        number_of_files++;

    while (files && files[i])
    {
        char **filestoprint = get_files(files[i]);
        // ft_printf("BRA");
        if (filestoprint == NULL)
        {
            if (((dir = opendir(files[i])) == NULL) && (stat(files[i], &st) != -1))
            {
                ft_printf("%s ", files[i]);
                files_found = 1;
            }
            i++;
            continue;
        }
        
        files_found = 1;
        if (number_of_files > 1 || display)
            printf("%s:\n", files[i]);
        show_files(filestoprint, options);
        if (number_of_files > 1 && files[i + 1])
            ft_printf("\n\n");
        i++;
    }
    return (files_found);
}

bool is_directory(char *file)
{
    struct stat st;
    if (stat(file, &st) == -1)
        return (false);
    if (S_ISDIR(st.st_mode))
        return (true);
    return (false);
}

void show_files(char **files, bool *options)
{
    int number_display = 0;
    for (int i = 0; files && files[i]; i++)
    {
        if (!options[2] && files[i][0] == '.')
            continue;
        ft_printf("%s", files[i]);
        // if this file is a directory and the -R option is set, add it to the list of directories to scan
        // if (options[1] && is_directory(files[i]))
        // {
        //     ft_printf("Find -R");
        // }
        number_display++;
        if (files[i + 1])
        {
            ft_putchar(' ');
            for (int j = 7 - ft_strlen(files[i]); j > 0; j--)
                ft_putchar(' ');
        }
    }
    // if (number_display > 0)
    //     ft_printf("\n");
}
