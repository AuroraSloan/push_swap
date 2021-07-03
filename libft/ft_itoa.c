#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	tmp = n;
	if (n < 0)
		tmp = -n;
	len = ft_numlen(tmp, 10);
	if (n < 0)
		len = ft_numlen(tmp, 10) + 1;
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (tmp)
	{
		str[len--] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (str);
}
