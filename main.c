#include "ft_ls.h"
// #include "parsing.c"


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
}

int main(int argc, char **argv)
{
    (void)argv;
    (void)argc;

    bool options[5] = {false, false, false, false, false};
    char **files = NULL;

    // parse the options
    parse_options(argc, argv, &files, options);

    // print the options
    show_options(options, files);


    
    return(0);
}