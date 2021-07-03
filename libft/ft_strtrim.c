#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new_str;

	if (!s1 || !set)
		return ((char *)s1);
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) && start < end)
		end--;
	new_str = ft_substr(s1, start, end - start + 1);
	if (!(new_str))
		return (NULL);
	return (new_str);
}
