#include "libft.h"

char	*ft_strldup(char const *s_ptr, int l)
{
	char	*dst;
	int	i;

	dst = (char *)malloc(sizeof(*dst) * l + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < l)
	{
		dst[i] = s_ptr[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
