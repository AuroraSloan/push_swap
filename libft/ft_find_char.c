#include "libft.h"

size_t	ft_find_char(const char *s, int c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 1;
	while (s[i])
	{
		if (s[i++] == (char)c)
			return (ret);
		ret++;
	}
	return (i);
}
