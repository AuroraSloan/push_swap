/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:21:12 by jthompso          #+#    #+#             */
/*   Updated: 2021/07/01 22:23:15 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

void	init_list_min(t_list *stack, t_int_data *int_data)
{
	int	count;

	count = 0;
	int_data->data = *(int *)stack->content;
	int_data->loc = 0;
	while (stack)
	{
		if (*(int *)stack->content < int_data->data)
		{
			int_data->data = *(int *)stack->content;
			int_data->loc = count;
		}
		stack = stack->next;
		count++;
	}
}

void	init_list_max(t_list *stack, t_int_data *int_data)
{
	int	count;

	count = 0;
	int_data->data = *(int *)stack->content;
	int_data->loc = 0;
	while (stack)
	{
		if (*(int *)stack->content > int_data->data)
		{
			int_data->data = *(int *)stack->content;
			int_data->loc = count;
		}
		stack = stack->next;
		count++;
	}
}
