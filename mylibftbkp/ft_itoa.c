/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:19:30 by jthompso          #+#    #+#             */
/*   Updated: 2021/05/27 16:09:18 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
