#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int	i;

	dst = (char *)malloc(sizeof(*dst) * ft_strlen(s1) + 1);
	if (!(dst))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
