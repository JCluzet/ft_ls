#include "ft_ls.h"

void print_files(t_file *head);

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
            // ft_printf("ls: %s: No such file or directory\n", files);
            return (NULL);
        }
        // ft_printf("%s ", files);
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
        // if (stat(files[i], &st) == -1)
        // {
        //     ft_printf("ls: %s: No such file or directory\n", files[i]);
        //     i++;
        //     continue;
        // }
        stat(files[i], &st);
        if (S_ISDIR(st.st_mode))
        {
            // use malloc to allocate the memory for the arrays, not realloc
            *foldertoscan = (char **)realloc(*foldertoscan, sizeof(char *) * (j + 1));
            (*foldertoscan)[j] = ft_strdup(files[i]);
            // ft_printf("directories detected : %s", files[i]);
            // ft_printf("%s ", files[i]);
            j++;
        }
        else
        {
            *filestoprint = (char **)realloc(*filestoprint, sizeof(char *) * (k + 1));
            (*filestoprint)[k] = ft_strdup(files[i]);
            // ft_printf("%s ", files[i]);
            // ft_printf("files detected : %s", files[i]);
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

void recursive_folder(t_file **head, bool *options)
{
    // if the last directory contain one directory or more, add them to the chain list
    t_file *tmp = *head;
    char **files = NULL;
    char *path = NULL;
    char **filestoprint = NULL;
    char **foldertoscan = NULL;

    while (tmp)
    {
        // if tmp is not the last element of the chain list, go to the next element
        if (tmp->next != NULL)
        {
            tmp = tmp->next;
            continue;
        }
        if (options[2])
        {
            if (ft_strcmp(tmp->name, ".") == 0 || ft_strcmp(tmp->name, "..") == 0)
            {
                tmp = tmp->next;
                continue;
            }
        }
        files = get_files(tmp->path);
        while (*files)
        {
            if (ft_strcmp(*files, ".") == 0 || ft_strcmp(*files, "..") == 0)
            {
                files++;
                continue;
            }
            path = ft_strjoin(tmp->path, "/");
            path = ft_strjoin(path, *files);
            if (is_directory(path))
            {
                add_file(head, *files, path);
                recursive_folder(head, options);
            }
            free(path);
            files++;
        }
        tmp = tmp->next;
    }
}

int main(int argc, char **argv)
{
    bool options[5] = {false, false, false, false, false};
    char **files = NULL;
    bool file_found = false;

    // declare the chain list for the files
    t_file *chain_list = NULL;

    parse_options(argc - 1, argv + 1, &files, options);

    // order the files
    files = alphanumeric_sort(files);

    // print the parsing
    // show_options(options, files);
    char **filestoprint = NULL;
    char **foldertoscan = NULL;

    divide_files(files, &filestoprint, &foldertoscan);

    // add all foldertoscan into the chain list
    while (*foldertoscan)
    {
        add_file(&chain_list, *foldertoscan, *foldertoscan);
        // if there is some folder into the folder to scan, add them to the chain list
        if (options[1])
        {
            // printf("there is an option\n");
            recursive_folder(&chain_list, options);
        }
        foldertoscan++;
    }

    // transform the chain list into an array
    foldertoscan = chain_list_to_array(chain_list);

    // exit(0);

    filestoprint = alphanumeric_sort(filestoprint);

    // first : display the no such file or directory error
    display_not_found(files);

    // second : display the files
    file_found = display_system(alphanumeric_sort(filestoprint), options, false);

    // third : display the directories

    // printf("foldertoscan: %s", foldertoscan[0]);
    if (file_found && !foldertoscan[0])
        ft_printf("\n");

    // ft_printf("file_found: %d", file_found);
    // ft_printf("foldertoscan[0]: %s", foldertoscan[0]);
    if (file_found && foldertoscan[0])
        ft_printf("\n\n");

    display_system(foldertoscan, options, filestoprint[0] && foldertoscan[0]);
    if (foldertoscan[0])
        ft_printf("\n");
    return (0);
}