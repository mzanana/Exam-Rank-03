#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef size
#define size 1000000
#endif

int main (int ac, char **av)
{
	char	*str;		// string that gonna contain the input from stdin
	ssize_t		readret;	// the read() return value
	int		i;			// full str
	char	c;			// character to fill str
	size_t		j;			// check same argument
	
	if (ac != 2 || !av[1] || !av[1][0])
		return (1);
	str = malloc (sizeof(char) * size);
	if (!str)
	{	
		write (2, "Error: ", 7);
		perror ("malloc");
		return (1);
	}
	i = 0;
	readret = 0;
	while ((readret = read(0, &c, 1)) > 0)
	{
		str[i++] = c;
	}
	str[i] = '\0';
	if (readret == -1)
	{
		write (2, "Error: ", 7);
		perror ("read");
		return (1);
	}
	i = 0;
	while (str[i])
	{
		j = 0;
		while (av[1][j] && str[i + j] && av[1][j] == str[i + j])
		{
			j++;
		}
		if (j == strlen(av[1]))
		{
			j = 0;
			while (j++ < strlen(av[1]))
			{
				write (1, "*", 1);
			}
			i = i + strlen(av[1]);
		}
		else
		{
			write (1, &str[i], 1);
			i++;
		}
	}
	free (str);
	return (0);
}
