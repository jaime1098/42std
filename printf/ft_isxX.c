#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int ft_isxX(va_list args, const char *text)
{
    unsigned int n;
    int hexa;

    if (*text == 'x')
    {
    n = va_arg(args, unsigned int);
    hexa = ft_decimaltohexadecimalx(n);
    return (hexa);
    }
    else
    {
    n = va_arg(args, unsigned int);
    hexa = ft_decimaltohexadecimalX(n);
    return (hexa);
    }
}

int ft_decimaltohexadecimalx(unsigned int decimal)
{
    char hexadecimal[20];
    int i;
    int aux;

    i = 0;
    while (decimal != 0)
    {
      int aux = decimal % 16;

      if (aux < 10)
        hexadecimal[i] = aux + '0';
     else
        hexadecimal[i] = aux + 'a' - 10;
      i++;
      decimal /= 16;
    }
    aux = i;
    i -= 1;
    while (i >= 0)
    {
      ft_putchar_fd (hexadecimal[i], 1);
        i--;
  }
    return (aux);
}

int ft_decimaltohexadecimalX(unsigned int decimal)
{
    char hexadecimal[20];
    int i;
    int aux;

    i = 0;
    while (decimal != 0)
    {
      int aux = decimal % 16;

      if (aux < 10)
        hexadecimal[i] = aux + '0';
     else
        hexadecimal[i] = aux + 'A' - 10;
      i++;
      decimal /= 16;
    }
    aux = i;
    i -= 1;
    while (i >= 0)
    {
      ft_putchar_fd (hexadecimal[i], 1);
        i--;
  }
    return (aux);
}