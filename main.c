#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include "parsing.c"


int main(int argc, char **argv)
{
    (void)argv;
    (void)argc;

    // create a tab of bools to store the options (-l, -R, -a, -r, -t)
    bool options[5] = {false, false, false, false, false};
    // create a tab of strings to store the files
    char **files = NULL;
    
    parse_options(argc, argv, &files, options);

    // print the options
    printf("Parsing : \n\n");
    for (int i = 0; i < 5; i++)
    {
        if (options[i])
        {
            if (i == 0)
                printf("options[%d] = l\n", i);
            else if (i == 1)
                printf("options[%d] = R\n", i);
            else if (i == 2)
                printf("options[%d] = a\n", i);
            else if (i == 3)
                printf("options[%d] = r\n", i);
            else if (i == 4)
                printf("options[%d] = t\n", i);
        }
    }
    for (int i = 0; files && files[i]; i++)
        printf("files[%d] = %s\n", i, files[i]);
    
    return(0);
}