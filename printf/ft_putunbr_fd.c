#include <unistd.h>

void	ft_putunbr_fd(unsigned int nb, int fd)
{
	char	a;

	if (nb >= 10)
		ft_putunbr_fd(nb / 10, fd);
	a = nb % 10 + '0';
	write(fd, &a, 1);
}
