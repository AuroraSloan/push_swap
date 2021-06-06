/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  main.c                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:43:58 by jthompso          #+#    #+#             */
/*  Updated: 2021/06/02 16:44:46 by jthompso           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <limits.h>

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

void	ft_swap(t_list *lst, char *operation)
{
	t_list	tmp;

	tmp.next = NULL;
	tmp.content = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp.content;
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
	ft_putendl(operation);
}

int	lst_sorted(t_list *lst)
{
	int	ret;

	ret = 1;
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
		{
			ret = 0;
			break ;
		}
		lst = lst->next;
	}
	return (ret);
}

int	lst_rev_sorted(t_list *lst)
{
	int	ret;

	ret = 1;
	while (lst->next)
	{
		if (*(int *)lst->content < *(int *)lst->next->content)
		{
			ret = 0;
			break ;
		}
		lst = lst->next;
	}
	return (ret);
}

void	duplicate_check(t_list *lst)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(int *)lst->content == *(int *)tmp->content)
			{
				ft_lstclear(&lst, ft_free);
				failed_exit("Error");
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void	overflow_check(int num, char *str, t_list *lst)
{
	char	*revert;

	revert = ft_itoa(num);
	if (ft_memcmp(revert, str, ft_strlen(str)) != 0)
	{
		ft_free(revert);
		ft_lstclear(&lst, ft_free);
		failed_exit("Error");
	}
	ft_free(revert);
}

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

void	push_swap_three(t_list **head)
{
	t_list	*stack_a;

	stack_a = *head;
	if (lst_rev_sorted(stack_a))
	{
		ft_swap(stack_a, "sa");
		ft_rev_rotate(head, "rra");
	}
	else if (head_is_max(stack_a))
		ft_rotate(head, "ra");
	else if (head_is_mid(stack_a) && *(int *)stack_a->next->content
		< *(int *)ft_lstlast(stack_a)->content)
		ft_swap(stack_a, "sa");
	else if (head_is_mid(stack_a))
		ft_rev_rotate(head, "rra");
	if (!lst_sorted(stack_a))
	{	
		ft_swap(stack_a, "sa");
		ft_rotate(head, "ra");
	}
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

void	ft_push(t_list **src, t_list **dest, char *operation)
{
	t_list	*src_stack;

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
	ft_putendl(operation);
}

void	push_swap_four(t_list **head)
{
	t_list	*stack_a;

	stack_a = *head;
	if (*(int *)stack_a->content > *(int *)ft_lstlast(stack_a)->content)
		ft_rotate(head, "ra");
	else if (*(int *)stack_a->content > *(int *)stack_a->next->next->content)
	{	
		ft_rev_rotate(head, "rra");
		ft_swap(*head, "sa");
		ft_rotate(head, "ra");
		ft_rotate(head, "ra");
	}
	else
		ft_swap(*head, "sa");
}

void	push_swap_small(t_list **head)
{	
	t_list	*stack_b;
	t_list	*stack_a;

	stack_b = NULL;
	stack_a = *head;
	if (ft_lstsize(stack_a) == 4)
	{
		if (!lst_sorted(stack_a->next))
		{
			ft_push(head, &stack_b, "pb");
			push_swap_three(head);
			ft_push(&stack_b, head, "pa");
		}	
		if (!lst_sorted(stack_a))
			push_swap_four(head);
	}
/*	else
	{
		if (!lst_sorted(stack_a->next))
		{
			ft_push(head, &stack_b, "pb");
			push_swap_three(head);
			ft_push(&stack_b, head, "pa");
		}	
		if (!lst_sorted(stack_a))
			push_swap_five(head);
	}*/
	//if (ft_lstsize(stack_b) == 1)
	//	ft_push(&stack_b, stack_b, &stack_a, "pa");
//	ft_lstprint(*head, ft_lstprint_int);
//	ft_putchar('\n');
//	ft_lstclear(head, ft_free);
//	ft_lstclear(&stack_b, ft_free);
}

void	push_swap(int argc, t_list **head)
{
	t_list	*stack_a;

	stack_a = *head;
	if (argc == 3 && *(int *)stack_a->content > *(int *)stack_a->next->content)
		ft_swap(stack_a, "sa");
	else if (argc == 4)
		push_swap_three(head);
	else if (argc == 5 || argc == 6)
		push_swap_small(head);
}

int	main(int argc, char **argv)
{
	int				i;
	int				num;
	t_list			*stack_a;
	unsigned int	data_size;

	i = 1;
	data_size = sizeof(int);
	if (argc > 501) //change later if argc > limit
		failed_exit("Error");
	if (argc > 1)
	{
		while (i < argc)
		{	
			overflow_check(ft_atoi(argv[1]), argv[1], stack_a);
			num = ft_atoi(argv[i++]);
			ft_lstadd_back(&stack_a, ft_lstnew(&num, data_size));
		}
		duplicate_check(stack_a);
		if (argc > 2 && !lst_sorted(stack_a))
			push_swap(argc, &stack_a);
	}
	system("leaks push_swap");
	exit(EXIT_SUCCESS);
}
