#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int main()
{
    int testft;
    int testorg;

    testft = ft_printf("Testft: %c\n", 'a');
    printf("lenft: %d\n", testft);
    testorg = printf("Testorg: %c\n", 'a');
    printf("lenorg: %d\n", testorg);
    return (0);
}