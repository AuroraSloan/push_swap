/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:35:53 by jthompso          #+#    #+#             */
/*   Updated: 2021/05/13 18:35:54 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr(long long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', 1);
	}
	i = ft_numlen(n, 10);
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (i);
}
