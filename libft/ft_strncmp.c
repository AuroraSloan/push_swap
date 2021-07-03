#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	size_t			i;

	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	if (new_s1[i] != new_s2[i])
		return (new_s1[i] - new_s2[i]);
	while (i < n - 1)
	{
		i++;
		if (new_s1[i] == '\0' && new_s2[i] == '\0')
			break ;
		if (new_s1[i] != new_s2[i])
			return (new_s1[i] - new_s2[i]);
	}
	return (0);
}
