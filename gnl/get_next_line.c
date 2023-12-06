#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;
	size_t length;
	int i;
	int j;

	length = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (length > 0)
		length = read(fd, buffer, BUFFER_SIZE);
		if ((int)length < 0)
		{
			free(buffer);
			return (NULL);
		}
	printf("%s\n", buffer);
	i = 0;
	while (buffer[i] != '\0')
	{
		j = 0;
		line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		while (buffer[i] != '\n' && buffer [i] != '\0')
			line[j++] = buffer[i++];
		line[j++] = '\n';
		line[j] = '\0';
		printf("%s\n", line);
		free (line);
		i++;
	}
	return(line);
}

void	leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("texto.txt", O_RDONLY);
	line = get_next_line(fd);
	free(line);
	atexit(leaks);
	close(fd);
	return (0);
}
