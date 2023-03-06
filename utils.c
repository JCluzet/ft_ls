#include "ft_ls.h"

char *ft_strdup(char *s)
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

int ft_strlen(char *str)
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

// Fonction de comparaison pour le tri
int cmp_time(const char *a, const char *b) {
    // what if the last modification file path between a and b
    // if it's the same, we compare the file name
    struct stat stat_a;
    struct stat stat_b;
    lstat(a, &stat_a);
    lstat(b, &stat_b);

    if (stat_a.st_mtime == stat_b.st_mtime) {
        return strcmp(a, b);
    }

    // printf file a and b and her last modification time
    printf("%s last modification time: %ld \t %s last modification time: %ld\n", a, stat_a.st_mtime, b, stat_b.st_mtime);

    if (stat_a.st_mtime > stat_b.st_mtime) {
        return -1;
    } else {
        return 1;
    }

}


static void	swap_files(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
			if (stat_i.st_mtime < stat_j.st_mtime ||
				(stat_i.st_mtime == stat_j.st_mtime && stat_i.st_mtim.tv_nsec < stat_j.st_mtim.tv_nsec))
				swap_files(&files[i], &files[j]);
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