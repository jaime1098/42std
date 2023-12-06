#include "get_next_line.h"

char *cutline(char *mybook)
{
	static char *mynewbook;
	int i;
	int j;

	i = 0;
	while (mybook[i] != '\0' && mybook[i] != '\n')
		i++;
	if (mybook[i] == '\0')
	{
		free(mybook);
		return (NULL);
	}
	mynewbook = malloc(sizeof(char) * (ft_strlen(mybook) - i + 1));
	i++;
	j = 0;
	while (mybook[i] != '\0')
		mynewbook[j++] = mybook[i++];
	mynewbook[j] = '\0';
	free(mybook);
	return (mynewbook);
}

char *readthebuffer(int fd, char *mybook)
{
char *buffer;
size_t length;

buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	length = 1;
	while (!ft_strchr(mybook, '\n') && (int)length > 0)
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if ((int)length > 0)
		{
			free(mybook);
			free(buffer);
			return (NULL);
		}
		buffer[length] = '\0';
		mybook = ft_strjoin(mybook, buffer);
	}
	free(buffer);
	return (mybook);
}

char	*get_next_line(int fd)
{
	static char *mybook;
	static char *mynewbook;
	char *line;
	int i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	mybook = readthebuffer(fd, mybook);
	if(!mybook)
		return (NULL);
	i = 0;
	while (mybook[i] != '\0' && mybook[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (mybook[i] != '\0' && mybook[i] != '\n')
		line[i++] = mybook[i];
	if(mybook[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	mynewbook = cutline(mybook);
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
	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++, line);
	free(line);
	atexit(leaks);
	close(fd);
	return (0);
}
