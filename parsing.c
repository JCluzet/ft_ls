#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void parse_options(int argc, char **argv, char ***files, bool *options)
{

    // if argc is 1, file is the current directory
    if (argc == 1)
    {
        *files = (char **)malloc(sizeof(char *) * 2);
        (*files)[0] = ft_strdup(".");
        (*files)[1] = NULL;
        // printf
        printf("VAMOS\n");
        return;
    }
    // parse if there is an option (between - and a letter)
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
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
                    printf("! option -%c is not working on ft_ls !\n", argv[i][j]);
            }
        }
        else
        {
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
}