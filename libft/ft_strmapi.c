#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*ptr;
	int	i;

	i = 0;
	if (!s)
		return ((char *)s);
	ptr = (char *)malloc(sizeof(*ptr) * ft_strlen(s) + 1);
	if (!(ptr))
		return (NULL);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
