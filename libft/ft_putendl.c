#include "libft.h"

void	ft_putendl(char *s)
{
	if (s == NULL)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}
