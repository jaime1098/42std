/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:29:02 by joltra-r          #+#    #+#             */
/*   Updated: 2023/12/16 00:29:04 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*bookwhitoutline(char *book)
{
	char	*newbook;
	int		i;
	int		j;

	i = 0;
	newbook = NULL;
	if (!book)
		return (NULL);
	while (book[i] && book[i] != '\n')
		i++;
	if (book[i] == '\0')
		return (free(book), book = NULL, NULL);
	newbook = malloc(ft_strlen(book) - i + 1);
	if (!newbook)
		return (free(newbook), NULL);
	i++;
	j = 0;
	while (book[i])
		newbook[j++] = book[i++];
	newbook[j] = '\0';
	free(book);
	return (newbook);
}

char	*cutlines(char *book)
{
	char	*line;
	int		i;

	i = 0;
	if (!book)
		return (NULL);
	while (book[i] && book[i] != '\n')
		i++;
	line = malloc(i + 2);
	i = 0;
	while (book[i] && book[i] != '\n')
	{
		line[i] = book[i];
		i++;
	}
	if (book[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*readbook(int fd, char *book)
{
	char	*buffer;
	int		size;

	size = 1;
	while (size > 0 && !ft_strchr_sl(book, '\n'))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (free(buffer), free(book), book = NULL, NULL);
		buffer[size] = '\0';
		book = ft_strjoin(book, buffer);
		free (buffer);
	}
	return (book);
}

char	*get_next_line(int fd)
{
	static char	*book;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	book = readbook(fd, book);
	if (!book || book[0] == '\0')
		return (free(book), book = NULL, NULL);
	line = cutlines(book);
	book = bookwhitoutline(book);
	return (line);
}
/*int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("texto.txt", O_RDONLY);
	//line = get_next_line(fd);
	//printf("RESULTADO\n%s\n", line);
	while ((line = get_next_line(fd)))
		printf("%d -> %s\n", lines++, line);
	//printf("%s%s", get_next_line(fd), get_next_line(fd));
	//printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}*/
