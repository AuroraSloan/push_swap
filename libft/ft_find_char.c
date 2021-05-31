/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  ft_find_char.c                                       :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: jthompso <jthompso@student.42tokyo.jp>       +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2021/05/15 14:16:47 by jthompso            #+#    #+#            */
/*  Updated: 2021/05/15 14:18:35 by jthompso           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_find_char(const char *s, int c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 1;
	while (s[i])
	{
		if (s[i++] == (char)c)
			return (ret);
		ret++;
	}
	return (i);
}
