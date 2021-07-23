#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char		*sub_s;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub_s = (char *)malloc(sizeof(*sub_s) * len + 1);
	if (!(sub_s))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
