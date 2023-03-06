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

int display_system(char **files, char options[5], bool display)
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
        // if (files[i][ft_strlen(files[i]) - 1] == '/')
        //     files[i][ft_strlen(files[i]) - 1] = '\0';
        char **filestoprint = get_files(files[i], options);
        // ft_printf("BRA");
        if (filestoprint == NULL)
        {
            if (((dir = opendir(files[i])) == NULL) && (stat(files[i], &st) != -1))
            {
                // if it's an executable, show RED and print it
                if (is_executable(files[i]))
                {
                    ft_printf("%s", RED);
                    ft_printf("%s", files[i]);
                    ft_printf("%s", RESET);
                }
                else
                    ft_printf("%s ", files[i]);
                files_found = 1;
            }
            i++;
            continue;
        }

        files_found = 1;
        if (!(i == 0 && is_in(options, 'R')))
        {
            if (number_of_files > 1 || display)
                printf("%s:\n", files[i]);
            // if this is the first file and the -R option is set
        }
        show_files(filestoprint, options, files[i]);
        if (number_of_files > 1 && files[i + 1])
            ft_printf("\n");
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

void show_files(char **files, char options[5], char *path)
{
    int number_display = 0;
    for (int i = 0; files && files[i]; i++)
    {
        if (!is_in(options, 'a') && files[i][0] == '.')
            continue;
        // COLORS
        if (is_directory(ft_strjoin(ft_strjoin(path, "/"), files[i])))
        {
            ft_printf("%s", BLUE);
        }
        // if the file is an executalbe
        else if (is_executable(ft_strjoin(ft_strjoin(path, "/"), files[i])))
        {
            ft_printf("%s", RED);
        }


        ft_printf("%s", files[i]);
        ft_printf("%s", RESET);
        number_display++;
        if (files[i + 1])
        {
            ft_putchar(' ');
            for (int j = 7 - ft_strlen(files[i]); j > 0; j--)
                ft_putchar(' ');
        }
    }
    if (number_display > 0)
        ft_printf("\n");
    // if (number_display > 0)
    //     ft_printf("\n");
}
