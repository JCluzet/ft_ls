#include "ft_ls.h"

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

int main(int argc, char **argv)
{
    bool options[5] = {false, false, false, false, false};
    char **files = NULL;

    parse_options(argc, argv, &files, options);

    // print the parsing
    // show_options(options, files);

    display_system(files, options);
    return (0);
}