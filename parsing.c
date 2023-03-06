#include "ft_ls.h"

void show_options(char options[5], char **files)
{
    // print the options
    ft_printf("Parsing : \n\n");
    ft_printf("options : ");
    for (int i = 0; i < 5; i++)
    {
        if (options[i])
        {
            ft_printf("%c, ", options[i]);
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

void parse_options(int argc, char **argv, char ***files, char options[5])
{
    bool files_found = false;
    int option_index = 0;
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
                // if the option is 'a' and a is not already in the options 

                if (argv[i][j] == 'l' && !is_in(options, 'l'))
                    options[option_index++] = 'l';
                else if (argv[i][j] == 'R' && !is_in(options, 'R'))
                    options[option_index++] = 'R';
                else if (argv[i][j] == 'a' && !is_in(options, 'a'))
                    options[option_index++] = 'a';
                else if (argv[i][j] == 'r' && !is_in(options, 'r'))
                    options[option_index++] = 'r';
                else if (argv[i][j] == 't' && !is_in(options, 't'))
                    options[option_index++] = 't';
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
    options[option_index] = '\0';
        // if there is no file, file is the current directory
        if (!*files)
        {
            *files = (char **)malloc(sizeof(char *) * 2);
            (*files)[0] = ft_strdup(".");
            (*files)[1] = NULL;
        }
}