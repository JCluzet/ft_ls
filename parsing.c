#include "ft_ls.h"

void show_options(bool *options, char **files)
{
    // print the options
    ft_printf("Parsing : \n\n");
    ft_printf("options : ");
    for (int i = 0; i < 5; i++)
    {
        if (options[i])
        {
            if (i == 0)
                ft_printf("l, ");
            else if (i == 1)
                ft_printf("R, ");
            else if (i == 2)
                ft_printf("a, ");
            else if (i == 3)
                ft_printf("r, ");
            else if (i == 4)
                ft_printf("t, ");
        }
    }
    if (!options[0] && !options[1] && !options[2] && !options[3] && !options[4])
        ft_printf("none\n");
    else
        ft_printf("\b\b  \n");
    for (int i = 0; files && files[i]; i++)
        ft_printf("files[%d] = %s\n", i, files[i]);
    ft_printf("\n\n");
}

void parse_options(int argc, char **argv, char ***files, bool *options)
{
    bool files_found = false;
    // if argc is 1, file is the current directory
    if (argc == 0)
    {
        *files = (char **)malloc(sizeof(char *) * 2);
        (*files)[0] = ft_strdup(".");
        (*files)[1] = NULL;
        return;
    }
    // parse if there is an option (between - and a letter)
    for (int i = 0; i < argc; i++)
    {
        // ft_printf("check\n");
        if (argv[i][0] == '-' && !files_found)
        {
            // ft_printf("option found\n");
            for (int j = 1; argv[i][j]; j++)
            {
                if (argv[i][j] == 'l')
                    options[0] = true;
                else if (argv[i][j] == 'R')
                    options[1] = true;
                else if (argv[i][j] == 'a')
                    options[2] = true;
                else if (argv[i][j] == 'r')
                    options[3] = true;
                else if (argv[i][j] == 't')
                    options[4] = true;
                else 
                    printf("! option -%c is not working on ft_ls project !\n", argv[i][j]);
            }
        }
        else
        {
            // // ft_printf("file found\n");
            files_found = true;
            // if there is a file, add it to the tab without using realloc
            if (!*files)
            {
                *files = (char **)malloc(sizeof(char *) * 2);
                (*files)[0] = ft_strdup(argv[i]);
                (*files)[1] = NULL;
            }
            else
            {
                int len = 0;
                while ((*files)[len])
                    len++;
                char **new_files = (char **)malloc(sizeof(char *) * (len + 2));
                for (int j = 0; j < len; j++)
                    new_files[j] = ft_strdup((*files)[j]);
                new_files[len] = ft_strdup(argv[i]);
                new_files[len + 1] = NULL;
                free(*files);
                *files = new_files;
            }
        }
    }
        // if there is no file, file is the current directory
        if (!*files)
        {
            *files = (char **)malloc(sizeof(char *) * 2);
            (*files)[0] = ft_strdup(".");
            (*files)[1] = NULL;
        }
}