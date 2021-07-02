/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:14:59 by jthompso          #+#    #+#             */
/*   Updated: 2021/07/02 16:02:26 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	ft_swap(t_list *lst, char *operation)
{
	t_list	tmp;

	tmp.next = NULL;
	tmp.content = lst->next->content;
	tmp.location = lst->next->location;
	lst->next->content = lst->content;
	lst->next->location = lst->location;
	lst->content = tmp.content;
	lst->location = tmp.location;
	if (operation)
		ft_putendl(operation);	
}

void	ft_rotate(t_list **head, char *operation)
{
	t_list	*old_head;
	t_list	*new_head;

	old_head = *head;
	new_head = *head;
	while (new_head->next)
		new_head = new_head->next;
	*head = old_head->next;
	old_head->next = NULL;
	new_head->next = old_head;
	if (operation)
		ft_putendl(operation);
}

void	ft_rev_rotate(t_list **head, char *operation)
{	
	t_list	*new_head;
	t_list	*new_end;

	new_head = *head;
	while (new_head->next)
	{
		new_end = new_head;
		new_head = new_head->next;
	}
	new_end->next = NULL;
	new_head->next = *head;
	*head = new_head;
	if (operation)
		ft_putendl(operation);
}

void	ft_push(t_list **src, t_list **dest, char *operation)
{
	t_list	*src_stack;
	t_list	*tmp;

	src_stack = *src;
	if (src_stack->next)
	{
		*src = src_stack->next;
		ft_lstadd_front(dest, ft_lstpop(&src_stack));
	}
	else
	{	
		*src = NULL;
		ft_lstadd_front(dest, src_stack);
	}
	tmp = *dest;
	if (operation)
		ft_putendl(operation);
}

t_list	*ft_lstpop(t_list **head)
{
	t_list	*pop;

	if (!*head)
		return (NULL);
	pop = *head;
	*head = pop->next;
	pop->next = NULL;
	return (pop);
}
