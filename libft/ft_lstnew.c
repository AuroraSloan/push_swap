/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:22:44 by jthompso          #+#    #+#             */
/*   Updated: 2021/05/28 22:18:49 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, size_t data_size)
{
	t_list	*new_element;
	size_t	i;

	new_element = malloc(sizeof(t_list));
	if (!(new_element))
		return (NULL);
	new_element->content = malloc(data_size);
	if (!new_element->content)
	{
		ft_free(new_element);
		return (NULL);
	}
	new_element->next = NULL;
	i = 0;
	while (i < data_size)
	{
		*(char *)(new_element->content + i) = *(char *)(content + i);
		i++;
	}
	return (new_element);
}
