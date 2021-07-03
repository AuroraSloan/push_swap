#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*s_ptr;

	if ((char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	i = ft_strlen(s);
	s_ptr = s + i;
	while (i-- >= 0)
	{
		if (*s_ptr == (char)c)
			return ((char *)s_ptr);
		s_ptr--;
	}
	return (NULL);
}
