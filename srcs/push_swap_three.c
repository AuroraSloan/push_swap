/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:16:37 by jthompso          #+#    #+#             */
/*   Updated: 2021/07/01 22:17:13 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

int	head_is_max(t_list *lst)
{
	return (*(int *)lst->content > *(int *)lst->next->content
		&& *(int *)lst->content > *(int *)ft_lstlast(lst)->content);
}

int	head_is_mid(t_list *lst)
{
	if (*(int *)lst->content > *(int *)lst->next->content
		&& *(int *)lst->content < *(int *)ft_lstlast(lst)->content)
		return (1);
	if (*(int *)lst->content < *(int *)lst->next->content
		&& *(int *)lst->content > *(int *)ft_lstlast(lst)->content)
		return (1);
	return (0);
}

t_list	*push_swap_three(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	if (lst_rev_sorted(*head))
	{
		ft_swap(*head, "sa");
		ft_rev_rotate(head, "rra");
	}
	else if (head_is_max(*head))
		ft_rotate(head, "ra");
	else if (head_is_mid(*head) && *(int *)tmp->next->content
		< *(int *)ft_lstlast(*head)->content)
		ft_swap(*head, "sa");
	else if (head_is_mid(*head))
		ft_rev_rotate(head, "rra");
	if (!lst_sorted(*head))
	{	
		ft_swap(*head, "sa");
		ft_rotate(head, "ra");
	}
	return (*head);
}
