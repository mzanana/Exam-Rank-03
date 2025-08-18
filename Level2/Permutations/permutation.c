#include <stdio.h>
#include <unistd.h>

void    swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void    sort(char *s)
{
    int x = 0;
    int y;

    while (s[x])
    {
        y = x + 1; 
        while (s[y])
        {
            if (s[x] > s[y])
                swap(&s[x], &s[y]);
            y++;
        }
        x++;
    }
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

void    prmt(char *s, int l , int r)
{
    if (l == r)
        return (puts(s), (void)0);
    else
    {
        int i = l;
        while (i <= r)
        {
            swap(&s[l], &s[i]);
            sort(s + l + 1);
            prmt(s, l + 1, r); 
            swap(&s[l], &s[i]);
            i++;
        }
    }
} 

int main (int ac, char **av)
{
    if (ac != 2)
        return (1);
    int n = ft_strlen(av[1]); 
    if (n == 0)
        return (write(1, "\n", 1), 0);
    sort(av[1]);
    prmt(av[1], 0, n - 1);
}

