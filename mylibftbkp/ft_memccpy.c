/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:23:27 by jthompso          #+#    #+#             */
/*   Updated: 2021/05/13 18:23:30 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	while (n > 0)
	{
		*dst_ptr = *src_ptr;
		if (*src_ptr == (unsigned char)c)
		{
			dst_ptr++;
			return (dst_ptr);
		}
		dst_ptr++;
		src_ptr++;
		n--;
	}
	return (NULL);
}
