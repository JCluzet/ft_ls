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
    struct stat st;

    if ((dir = opendir(files)) == NULL)
    {
        // check if the files is a file and not a directory and print it
        if (stat(files, &st) == -1)
        {
            ft_printf("ls: %s: No such file or directory\n", files);
            return (NULL);
        }
        ft_printf("%s ", files);
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

int divide_files(char **files, char ***filestoprint, char ***foldertoscan)
{
    int i = 0;
    int j = 0;
    int k = 0;
    struct stat st;

    // divide the files in two arrays, one for files and one for directories
    // use stat to check if the file is a directory or not
    // use malloc to allocate the memory for the arrays
    while (files[i])
    {
        if (stat(files[i], &st) == -1)
        {
            ft_printf("ls: %s: No such file or directory\n", files[i]);
            i++;
            continue;
        }
        if (S_ISDIR(st.st_mode))
        {
            // use malloc to allocate the memory for the arrays, not realloc
            *foldertoscan = (char **)realloc(*foldertoscan, sizeof(char *) * (j + 1));
            (*foldertoscan)[j] = ft_strdup(files[i]);
            j++;
        }
        else
        {
            *filestoprint = (char **)realloc(*filestoprint, sizeof(char *) * (k + 1));
            (*filestoprint)[k] = ft_strdup(files[i]);
            // ft_printf("%s ", files[i]);
            k++;
        }
        i++;
    }
    *foldertoscan = (char **)realloc(*foldertoscan, sizeof(char *) * (j + 1));
    (*foldertoscan)[j] = NULL;
    *filestoprint = (char **)realloc(*filestoprint, sizeof(char *) * (k + 1));
    (*filestoprint)[k] = NULL;
    return (0);
}

int main(int argc, char **argv)
{
    bool options[5] = {false, false, false, false, false};
    char **files = NULL;

    parse_options(argc, alphanumeric_sort(argv), &files, options);

    // print the parsing
    // show_options(options, files);
    char** filestoprint = NULL;
    char** foldertoscan = NULL;

    divide_files(files, &filestoprint, &foldertoscan);

    // printf("filestoprint: %s\n", filestoprint[0]);
    display_system(alphanumeric_sort(filestoprint), options, false);
    if (filestoprint[0] && !foldertoscan[0])
        ft_printf("\n");
    else if (filestoprint[0] && foldertoscan[0])
        ft_printf("\n\n");

    // printf("foldertoscan: %s\n", foldertoscan[0]);

    display_system(foldertoscan, options, filestoprint[0] && foldertoscan[0]);
    // ft_printf("\n");
    return (0);
}