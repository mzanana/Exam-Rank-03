#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE   ((SIZE > 0) * (SIZE) + (SIZE < 0))

#ifndef SIZE
# define SIZE 42
#endif


char	*get_next_line(int fd)
{
	static char buff[BUFFSIZE];
	char *line;
	static int r = 0;
	static int bp = 0;
	int y = 0;

	line = malloc (sizeof(char)*4096);
	if (!line)
	{
		printf ("malloc : ");
		return (NULL);
	}
	if (fd < 0 || SIZE <= 0)
		return (free(line), NULL);
	while (1)
	{
		if (bp >= r)
		{
			r = read(fd, buff, SIZE);
			bp = 0;
		}
		if (r <= 0)
			break ;
		line[y++] = buff[bp++];
		if (buff[bp - 1] == '\n')
			break ;
	}
	line[y] = '\0';
	if (y == 0)
		return (free(line), NULL);
	return (line);
}
int main()
{
	char *str;
	int fd = open ("ff", O_RDONLY);
	str = get_next_line(fd);
//	str = get_next_line(fd);
	
	printf ("%s", str);
	free (str);
	
	return 0;}
