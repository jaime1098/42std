#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*book;
	char		*line;
	int			size;
	int			i;
	int			j;

	i = 0;
	j = 0;
	size = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	book = malloc(sizeof(char));
	if (!book)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	while (size > 0 && buffer[j] != '\n')
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		j = 0;
		while (buffer[j] != '\n' && buffer[j])
		{
			line[i++] = buffer[j++];
			line = realloc(line, sizeof(char) * (i + 1));
			if (!line)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	free(buffer);
	line[i] = '\0';
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("texto.txt", O_RDONLY);
	while ((line = get_next_line(fd)) && lines < 6)
		printf("%d -> %s\n", lines++, line);
	close(fd);
	return (0);
}
