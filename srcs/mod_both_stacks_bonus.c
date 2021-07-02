/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_both_stacks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:35:09 by jthompso          #+#    #+#             */
/*   Updated: 2021/07/02 22:29:39 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	swap_both(t_list **stack_a, t_list **stack_b, char *operation)
{
	ft_swap(*stack_a, NULL);
	ft_swap(*stack_b, NULL);
	if (operation)
		ft_putendl(operation);
}

void	rotate_both(t_list **stack_a, t_list **stack_b, char *operation)
{
	ft_rotate(stack_a, NULL);
	ft_rotate(stack_b, NULL);
	if (operation)
		ft_putendl(operation);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b, char *operation)
{
	ft_rev_rotate(stack_a, NULL);
	ft_rev_rotate(stack_b, NULL);
	if (operation)
		ft_putendl(operation);
}
