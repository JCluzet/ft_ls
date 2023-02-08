#include "ft_ls.h"
// #include "parsing.c"

char **alphanumeric_sort(char **files)
{
    // sort the files in alphabetical order
    int i = 0;
    int j = 0;
    char *tmp = NULL;

    while (files[i])
    {
        j = i + 1;
        while (files[j])
        {
            if (ft_strcmp(files[i], files[j]) > 0)
            {
                tmp = files[i];
                files[i] = files[j];
                files[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (files);
}

char **get_files(char *files)
{
    DIR *dir;
    struct dirent *sd;
    char **filestoprint = NULL;
    int i = 0;

    if ((dir = opendir(files)) == NULL)
    {
        ft_printf("ls: %s: No such file or directory\n", files);
        return (NULL);
    }
    while ((sd = readdir(dir)) != NULL)
    {
        filestoprint = (char **)realloc(filestoprint, sizeof(char *) * (i + 1));
        filestoprint[i] = ft_strdup(sd->d_name);
        i++;
    }
    filestoprint = (char **)realloc(filestoprint, sizeof(char *) * (i + 1));
    filestoprint[i] = NULL;
    closedir(dir);
    return (alphanumeric_sort(filestoprint));
}


void show_files(char **files, bool *options)
{
    for (int i = 0; files && files[i]; i++)
    {
        if (!options[2] && files[i][0] == '.')
            continue;
        ft_printf("%s", files[i]);
        if (files[i + 1])
        {
            ft_putchar(' ');
            for (int j = 7 - ft_strlen(files[i]); j > 0; j--)
                ft_putchar(' ');
        }
    }
    if (files)
        ft_putchar('\n');
}

int main(int argc, char **argv)
{
    (void)argv;
    (void)argc;
    int i = 0;

    // ft_printf("test");
    bool options[5] = {false, false, false, false, false};
    char **files = NULL;

    // parse the options
    parse_options(argc, argv, &files, options);

    // print the options
    // show_options(options, files);

    while (files && files[0])
    {
        // printf("files[0] = %s\n", files[0]);
        char **filestoprint = get_files(files[i]);
        show_files(filestoprint, options);
        i++;
        files++;
    }

    return (0);
}