#include "ft_ls.h"

// Create sort_files function, that a chain list and return another chain list sorted
// we sort by name
node *sort_files(node *head)
{
    // if there is no file, we return NULL
    if (head == NULL || head->next == NULL)
        return (head);
    // sort by name
    for (node *i = head; i != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (ft_strcmp(i->name, j->name) > 0)
            {
                char *tmp = i->name;
                i->name = j->name;
                j->name = tmp;

                tmp = i->path;
                i->path = j->path;
                j->path = tmp;
            }
        }
    }


    if (is_in(head->options, 't'))
    {
        for (node *i = head; i != NULL; i = i->next)
        {
            for (node *j = i->next; j != NULL; j = j->next)
            {
                if (cmp_time(i, j) > 0)
                {
                    char *tmp = i->name;
                    i->name = j->name;
                    j->name = tmp;

                    tmp = i->path;
                    i->path = j->path;
                    j->path = tmp;
                }
            }
        }
    }

    if (is_in(head->options, 'r'))
    {
        node *current = head;
        node *prev = NULL;
        node *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    treat_files(head);
    return (head);
}