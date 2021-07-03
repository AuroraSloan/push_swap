#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;

	s_ptr = s;
	while (n-- > 0)
	{
		if (*s_ptr == (const unsigned char)c)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}
