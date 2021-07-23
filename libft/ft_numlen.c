#include "libft.h"

size_t	ft_numlen(long long n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
