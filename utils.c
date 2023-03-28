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
    int len;
    if (s1 == NULL)
        len = ft_strlen(s2);
    else if (s2 == NULL)
        len = ft_strlen(s1);
    else
        len = ft_strlen(s1) + ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    while (s1 && s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
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

#if defined(__APPLE__) || defined(__MACH__)

int cmp_time(node *first, node *second)
{
    struct stat stat_a;
    struct stat stat_b;

    lstat(first->path, &stat_a);
    lstat(second->path, &stat_b);

    if (stat_a.st_mtimespec.tv_sec == stat_b.st_mtimespec.tv_sec)
    {
        if (stat_a.st_mtimespec.tv_nsec == stat_b.st_mtimespec.tv_nsec)
        {
            return strcmp(first->path, second->path);
        }
        return (stat_a.st_mtimespec.tv_nsec > stat_b.st_mtimespec.tv_nsec) ? -1 : 1;
    }

    return (stat_a.st_mtimespec.tv_sec > stat_b.st_mtimespec.tv_sec) ? -1 : 1;
}

#elif defined(__linux__)

int cmp_time(node *first, node *second)
{
    struct stat stat_a;
    struct stat stat_b;

    lstat(first->path, &stat_a);
    lstat(second->path, &stat_b);

    if (stat_a.st_mtim.tv_sec == stat_b.st_mtim.tv_sec)
    {
        if (stat_a.st_mtim.tv_nsec == stat_b.st_mtim.tv_nsec)
        {
            return strcmp(first->path, second->path);
        }
        return (stat_a.st_mtim.tv_nsec > stat_b.st_mtim.tv_nsec) ? -1 : 1;
    }

    return (stat_a.st_mtim.tv_sec > stat_b.st_mtim.tv_sec) ? -1 : 1;
}

#else
#error "OS non pris en charge"
#endif

bool is_dir(char *file)
{
    struct stat st;
    if (stat(file, &st) == -1)
        return (false);
    if (S_ISDIR(st.st_mode))
        return (true);
    return (false);
}

static void swap_files(char **a, char **b)
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