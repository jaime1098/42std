#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*completestr(char const *s1, char const *s2, char *cstr, size_t l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)l - 1)
	{
		while (s1[i] != '\0')
		{
			cstr[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			cstr[i] = s2[j];
			j++;
			i++;
		}
	}
	cstr[i] = '\0';
	return (cstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcomplete;
	size_t	length;
	char	*result;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	strcomplete = malloc(length);
	if (strcomplete == NULL)
		return (NULL);
	result = completestr(s1, s2, strcomplete, length);
	return (result);
}
char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*str != ch && *str != '\0')
		str++;
	if (*str == ch)
		return ((char *)str);
	else
		return (NULL);
}
