#include "get_next_line.h"

char	*cutlines(char *book)
{
	char *line;
	int i;

	i = 0;
	while (book[i] && book[i] != '\n')
		i++;
	line = malloc(i + 2);
	i = 0;
	while (book[i] && book[i] != '\n')
		line[i++] = book[i];
	if (book[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	printf("PINGA\n%s\n", line);
	return (line);
}

char	*readbook(int fd, char *book)
{
	char *buffer;
	int size;

	size = 1;
	book = malloc(sizeof(char));
	book[0] = '\0';
	while (size > 0 && !ft_strchr(buffer, '\n'))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		book = ft_strjoin(book, buffer);
		//printf("%d\n", size);
		free(buffer);
	}
	//printf("%s\n", book);
	return(book);
}

char	*get_next_line(int fd)
{
	static char *book;
	char *line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if(!book || !ft_strchr(book, '\n'))
		book = readbook(fd, book);
	//printf("%s\n", book);
	line = cutlines(book);
	return(book);
}
/*{
	static char *bigdick;
	if (fd < 0)
		return (NULL);
	if (!pollagorda && si hay un salto de linea no quiero leer, solo leo si no hay salto de linea)
		funcion para leer;
	funcion para sacar la linea del buffer que he creado en la funcion para leer
	comprobar si la linea se ha creado bien ;
	gestionar la statica (el read no lee 2 vecces la misma cosa entonces tendre que guardarme la info)
	devolver la linea;
}*/

int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("texto.txt", O_RDONLY);
	line = get_next_line(fd);
	//printf("PINGA\n%s\n", line);
	//while ((line = get_next_line(fd)) && lines < 6)
	//	printf("%d -> %s\n", lines++, line);
	close(fd);
	return (0);
}
