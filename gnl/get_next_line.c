#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	size_t	lenght;
	int		i;
	int		j;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = NULL;
	lenght = read(fd, buffer, BUFFER_SIZE);
	if (lenght < 0) // Error in read
		return (NULL);
	while (lenght > 0)
	{
		buffer[lenght] = '\0'; // Null-terminate the buffer
		i = 0;
		while (buffer)
		{
			// Find newline character
			if (buffer[i] == '\n')
			{
				// Allocate memory for line and copy content
				line = (char *)malloc((i + 1) * sizeof(char));
				if (!line)
				{
					free(buffer);
					return (NULL);
				}
				j = 0;
				// Copy the line into the allocated memory
				while (j++ = < i)
					line[j] = buffer[j];
				line[i] = '\0'; // Null-terminate the line
				return (line);
			}
			i++;
		}
	}
	free(buffer);
	return (NULL);
}
