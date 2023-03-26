#include "ft_ls.h"

char *ft_strdup(const char *s)
{
    char *moulitruc;
    int i;
    int u;

    i = 0;
    u = (int)ft_strlen(s);
    moulitruc = malloc(sizeof(char) * u + 1);
    if (moulitruc == NULL)
        return (NULL);
    while (s[i])
    {
        moulitruc[i] = s[i];
        i++;
    }
    moulitruc[i] = '\0';
    return (moulitruc);
}

void free_node(node *head)
{
    while (head)
    {
        node *tmp = head;
        head = head->next;
        free(tmp->path);
        free(tmp->name);
        free(tmp);
    }
    free(head);
}

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

char *ft_strrev(char *str)
{
    int i = 0;
    int j = ft_strlen(str) - 1;
    char tmp;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return (str);
}

char *ft_itoa(int n)
{
    char *str;
    int i = 0;
    int sign = 1;
    int len = 0;
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    if (n < 0)
    {
        sign = -1;
        n = -n;
        len++;
    }
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    n = (sign == -1) ? -n : n;
    while (n > 0)
    {
        str[i++] = n % 10 + '0';
        n /= 10;
    }
    if (sign == -1)
        str[i++] = '-';
    str[i] = '\0';
    return (ft_strrev(str));
}

void ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + '0');
}

int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int i = 0;
    int j = 0;
    int len = ft_strlen(s1) + ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}

char **chain_list_to_array(t_file *head)
{
    t_file *tmp;
    char **array;
    int i = 0;
    int len = 0;

    tmp = head;
    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }
    array = (char **)malloc(sizeof(char *) * (len + 1));
    tmp = head;
    while (tmp)
    {
        array[i] = ft_strdup(tmp->path);
        i++;
        tmp = tmp->next;
    }
    array[i] = NULL;
    return (array);
}

// is_executable function
bool is_executable(char *path)
{
    struct stat buf;
    if (stat(path, &buf) == -1)
        return (false);
    if (buf.st_mode & S_IXUSR)
        return (true);
    return (false);
}

bool is_in(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (true);
        i++;
    }
    return (false);
}

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include <time.h>

#include <time.h>


// if this is a mac 
// #ifdef __APPLE__




// int cmp_time(node *first, node *second) {
//     // what if the last modification file path between a and b
//     // if it's the same, we compare the file name
//     struct stat stat_a;
//     struct stat stat_b;
//     lstat(first->path, &stat_a);
//     lstat(second->path, &stat_b);

//     // if (stat_a.st_mtime == stat_b.st_mtime) {
//     //     return strcmp(first->path, second->path);
//     // }

//     // printf file a and b and her last modification time
//     char time_a[100], time_b[100];
//     strftime(time_a, 100, "%Y-%m-%d %H:%M:%S", localtime(&stat_a.st_mtime));
//     strftime(time_b, 100, "%Y-%m-%d %H:%M:%S", localtime(&stat_b.st_mtime));
//     // ft_printf("%s last modification time: %s\n", first->path, time_a);
//     // ft_printf("%s last modification time: %s\n", second->path, time_b);

//     // ft_printf("between %s and %s, %s is the last modification file\n\n", first->path, second->path, (stat_a.st_mtime > stat_b.st_mtime) ? first->path : second->path);
//         // printf("time: stat.a.st_mtime: %ld\n", stat_a.st_mtime);
//         // printf("time: stat.b.st_mtime: %ld\n\n\n", stat_b.st_mtime);

//     // if they have the same last modification time, we compare the file name
//     if (stat_a.st_mtimespec.tv_sec == stat_b.st_mtimespec.tv_sec) {
//         return strcmp(first->path, second->path);
//     }

//     return (stat_a.st_mtime > stat_b.st_mtime) ? -1 : 1;
// }
// #else
// LINUX VERSION



#if defined(__APPLE__) || defined(__MACH__)
int cmp_time(node *first, node *second) {
    struct stat stat_a;
    struct stat stat_b;

    lstat(first->path, &stat_a);
    lstat(second->path, &stat_b);

    if (stat_a.st_mtimespec.tv_sec == stat_b.st_mtimespec.tv_sec) {
        return strcmp(first->path, second->path);
    }

    return (stat_a.st_mtimespec.tv_sec > stat_b.st_mtimespec.tv_sec) ? -1 : 1;
}
#elif defined(__linux__)
int cmp_time(node *first, node *second) {
    struct stat stat_a;
    struct stat stat_b;

    lstat(first->path, &stat_a);
    lstat(second->path, &stat_b);

    if (stat_a.st_mtim.tv_sec == stat_b.st_mtim.tv_sec) {
        return strcmp(first->path, second->path);
    }

    return (stat_a.st_mtim.tv_sec > stat_b.st_mtim.tv_sec) ? -1 : 1;
}
#else
    #error "OS non pris en charge"
#endif



// #endif

char *get_date_modification(char *path)
{
    struct stat attribut;
    stat(path, &attribut);
    char *date_modification = ctime(&attribut.st_mtime);
    return (date_modification);
}

bool is_sorted_time(node *head)
{
    node *tmp = head;
    while (tmp->next)
    {
        if (cmp_time(tmp, tmp->next) == 1)
            return (false);
        tmp = tmp->next;
    }
    return (true);
}

// main.o a 00:28:39 1678491036
// utils.o 00:25:43  1678491036

bool is_dir(char *file)
{
    struct stat st;
    if (stat(file, &st) == -1)
        return (false);
    if (S_ISDIR(st.st_mode))
        return (true);
    return (false);
}


static void	swap_files(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

bool path_exists(char *path)
{
    struct stat buf;
    if (stat(path, &buf) == -1)
        return (false);
    return (true);
}

char	**sort_by_time(char **files)
{
	if (!files)
		return (NULL);
	int i, j, n = 0;
	while (files[n])
		n++;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			struct stat stat_i, stat_j;
			if (stat(files[i], &stat_i) == -1)
				return (NULL);
			if (stat(files[j], &stat_j) == -1)
				return (NULL);
            #if defined(__APPLE__)
            if (stat_i.st_mtimespec.tv_sec < stat_j.st_mtimespec.tv_sec ||
                (stat_i.st_mtimespec.tv_sec == stat_j.st_mtimespec.tv_sec && stat_i.st_mtimespec.tv_nsec < stat_j.st_mtimespec.tv_nsec))
                swap_files(&files[i], &files[j]);
            #else
			if (stat_i.st_mtime < stat_j.st_mtime ||
				(stat_i.st_mtime == stat_j.st_mtime && stat_i.st_mtim.tv_nsec < stat_j.st_mtim.tv_nsec))
				swap_files(&files[i], &files[j]);
            #endif
		}
	}
	return (files);
}



char **reverse_order(char **files)
{
    int i = 0;
    int j = 0;
    char *temp;
    while (files[i])
        i++;
    i--;
    while (j < i)
    {
        temp = files[j];
        files[j] = files[i];
        files[i] = temp;
        j++;
        i--;
    }
    return (files);
}

char **sort_by_alphabetical_order(char **files)
{
    int i = 0;
    int j = 0;
    char *temp;
    while (files[i])
        i++;
    i--;
    while (j < i)
    {
        if (ft_strcmp(files[j], files[j + 1]) > 0)
        {
            temp = files[j];
            files[j] = files[j + 1];
            files[j + 1] = temp;
            j = 0;
        }
        else
            j++;
    }
    return (files);
}