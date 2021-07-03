#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = ft_memchr(s, c, (ft_strlen(s) + 1));
	return (ret);
}
