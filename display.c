#include "ft_ls.h"

int display_system(char **files, bool *options)
{
    int number_of_files = 0;
    int i = 0;
    while (files && files[number_of_files])
        number_of_files++;

    while (files && files[i])
    {
        char **filestoprint = get_files(files[i]);
        if (number_of_files > 1)
            printf("%s:\n", files[i]);
        show_files(filestoprint, options);
        if (number_of_files > 1 && files[i + 1])
            ft_printf("\n");
        i++;
    }
    return (0);
}

void show_files(char **files, bool *options)
{
    int number_display = 0;
    for (int i = 0; files && files[i]; i++)
    {
        if (!options[2] && files[i][0] == '.')
            continue;
        ft_printf("%s", files[i]);
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
}
