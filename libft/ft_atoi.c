#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long long int	nbr;
	long long int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		nbr = nbr * 10 + (str[i++] - '0');
		if (nbr < 0)
			return ((sign + 1) / -2);
	}
	return ((int)(nbr * sign));
}
