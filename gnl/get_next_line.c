#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			size;
	int	i;
	int j;

	i = 0;
	size = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = malloc (sizeof (char) * i + 1);
	if (!buffer)
		return (NULL);
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(buffer);
			return (NULL);
		}
		j = 0;
		while (buffer[i] && buffer[i] != '\n')
			line[i++] = buffer[j++];
	}
	printf("%s\n", line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("texto.txt", O_RDONLY);
	line = get_next_line(fd);
	printf ("%s", line);
	//while ((line = get_next_line(fd)))
	//	printf("%d -> %s\n", lines, line);
	close(fd);
	return (0);
}
