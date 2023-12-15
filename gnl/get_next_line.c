#include "get_next_line.h"

char	*bookwhitoutline(char *book)
{
	char *newbook;
	int i;
	int j;

	i = 0;
	if (!book)
      return (NULL);
	printf("BOOK\n%s\n", book);
	while (book[i] && book[i] != '\n')
		i++;
	if (book[i] == '\0')
	{
		free(book);
		return (NULL);
	}
	newbook = malloc(ft_strlen(book) - i + 1);
	if (!newbook)
		return (NULL);
	i++;
	j = 0;
	while (book[i])
		newbook[j++] = book[i++];
	newbook[j] = '\0';
	free(book);
	return(newbook);
}
char	*cutlines(char *book)
{
	char *line;
	int i;

	i = 0;
	if (!book)
		return (NULL);
	while (book[i] && book[i] != '\n')
		i++;
	line = malloc(i + 2);
	i = 0;
	while (book[i] && book[i] != '\n')
		line[i++] = book[i];
	if (book[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	printf("LINE\n%s\n", line);
	return (line);
}

char	*readbook(int fd, char *book)
{
	char *buffer;
	int size;

	size = 1;
	book = malloc(sizeof(char));
	book[0] = '\0';
	while (size > 0/* && !ft_strchr(buffer, '\n')*/)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(buffer);
			free(book);
			return (NULL);
		}
		buffer[size] = '\0';
		book = ft_strjoin(book, buffer);
		//printf("SIZE\n%d\n", size);
		free(buffer);
	}
	//printf("BOOK\n%s\n", book);
	return(book);
}

char	*get_next_line(int fd)
{
	static char *book;
	char *line;

	//printf("TEST\n");
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if(!book)
		book = readbook(fd, book);
	if (book[0] == '\0')
	{
		free(book);
		return (NULL);
	}
	//printf("BOOK\n%s\n", book);
	line = cutlines(book);
	//printf("LINE\n%s", line);
	book = bookwhitoutline(book);
	printf("NEWBOOK\n%s\n", book);
	return (line);
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
	//line = get_next_line(fd);
	//printf("RESULTADO\n%s\n", line);
	while (line = get_next_line(fd))
		printf("%d -> %s\n", lines++, line);
	close(fd);
	return (0);
}
