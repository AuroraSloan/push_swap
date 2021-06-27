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
#include "../includes/push_swap.h"

void	push_swap_large(t_list **stack_a, t_list **stack_b, t_info *info);

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
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

t_list	*ft_swap(t_list *lst, char *operation)
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
	return (lst);
}

void	swap_both(t_list **stack_a, t_list **stack_b, char *operation)
{
	*stack_a = ft_swap(*stack_a, NULL);
	*stack_b = ft_swap(*stack_b, NULL);
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

void	rotate_both(t_list **stack_a, t_list  **stack_b, char *operation)
{
	ft_rotate(stack_a, NULL);
	ft_rotate(stack_b, NULL);
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

void	rev_rotate_both(t_list **stack_a, t_list **stack_b, char *operation)
{
	ft_rev_rotate(stack_a, NULL);
	ft_rev_rotate(stack_b, NULL);
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
//	tmp->location = src_stack->location;
	if (operation)
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

t_list	*push_swap_three(t_list **head)
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
	return (*head);
}

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

void	push_min_max(t_list **src, t_list **dest, t_int_data int_data)
{
	t_list	*stack;

	stack = *src;
	if ((double)int_data.loc >= (double)ft_lstsize(stack) / 2.0)
	{	
		while (*(int *)stack->content != int_data.data)
		{	
			ft_rev_rotate(src, "rra");
			stack = *src;
		}
	}
	else
	{	
		while (*(int *)stack->content != int_data.data)
		{	
			ft_rotate(src, "ra");
			stack = *src;
		}
	}
	if (!lst_sorted(*src))
		ft_push(src, dest, "pb");
}

void	push_swap_small(t_list **head, t_list **stack_b)
{
	t_int_data	int_data;

	init_list_min(*head, &int_data);
	push_min_max(head, stack_b, int_data);
	if (ft_lstsize(*head) == 4)
	{	
		init_list_min(*head, &int_data);
		push_min_max(head, stack_b, int_data);
	}
	push_swap_three(head);
	if (ft_lstsize(*stack_b) == 2)
		ft_push(stack_b, head, "pa");
	if (ft_lstsize(*stack_b) == 1)
		ft_push(stack_b, head, "pa");
}

/*void	push_swap_large(t_list **head)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_int_data	int_data;

	stack_a = *head;
	stack_b = NULL;
	init_list_max(stack_a, &int_data);
	stack_a = push_min_max(head, &stack_b, int_data);
	*head = ft_push(&stack_a, &stack_b, "pb");
	if (*(int *)stack_b->content < *(int *)stack_b->next->content)
		stack_b = ft_swap(stack_b, "sb");
	while (ft_lstsize(stack_a))
	{
		*head = ft_push(&stack_a, &stack_b, "pb");
		if (*(int *)stack_b->content < *(int *)stack_b->next->content)
			stack_b = ft_swap(stack_b, "sb");
		while (*(int *)stack_b->next->content < *(int *)stack_b->next->next->content
			&& *(int *)stack_b->next->next->content != int_data.data)
		{	
			stack_b = ft_rotate(&stack_b, "rb");
			stack_b = ft_swap(stack_b, "sb");
		}
		while (*(int *)stack_b->content != int_data.data)
			stack_b = ft_rev_rotate(&stack_b, "rrb");
	}
	while (ft_lstsize(stack_b))
		ft_push(&stack_b, head, "pa");
}*/

//my algo
/*void	push_swap_large(t_list **head)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_int_data	max_data;
	t_int_data	min_data;

	stack_a = *head;
	stack_b = NULL;
	init_list_max(stack_a, &max_data);
	init_list_min(stack_a, &min_data);	
	stack_a = push_min_max(head, &stack_b, min_data);
	stack_a = push_min_max(head, &stack_b, max_data);	
	*head = ft_push(&stack_a, &stack_b, "pb");
	stack_b = ft_swap(stack_b, "sb");
	while (ft_lstsize(stack_a))
	{
		if (*(int *)stack_b->content > *(int *)stack_a->content)
		{	
			while (ft_lstsize(stack_a) && *(int *)stack_b->content > *(int *)stack_a->content)
				stack_b = ft_rotate(&stack_b, "rb");
			*head = ft_push(&stack_a, &stack_b, "pb");
		}
		if (ft_lstsize(stack_a) && *(int *)stack_b->content < *(int *)stack_a->content)
		{	
			while (ft_lstsize(stack_a) && *(int *)stack_b->content < *(int *)stack_a->content) 
				stack_b = ft_rev_rotate(&stack_b, "rrb");
			*head = ft_push(&stack_a, &stack_b, "pb");
			stack_b = ft_swap(stack_b, "sb");
		}
	}
	init_list_max(stack_b, &max_data);
	if (max_data.loc < ft_lstsize(stack_b) / 2)
	{
		while (*(int *)stack_b->content != max_data.data)
			stack_b = ft_rev_rotate(&stack_b, "rrb");
	}
	else
	{
		while (*(int *)stack_b->content != max_data.data)
			stack_b = ft_rotate(&stack_b, "rb");
	}
	while (ft_lstsize(stack_b))
		ft_push(&stack_b, head, "pa");
	ft_lstprint(*head, ft_lstprint_int);
}*/

//optimized push lowest
/*void	push_swap_large(t_list **head)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_int_data	min_data;

	stack_b = NULL;	
	while (ft_lstsize(*head) && !lst_sorted(*head))
	{
		init_list_min(*head, &min_data);
		if (min_data.loc < ft_lstsize(*head) / 2)
			*head = push_min_max(head, &stack_b, min_data);
		else
			*head = ft_rotate(head, "ra");
		if (ft_lstsize(*head) == 2)
		{
			stack_a = *head;
			if (*(int *)stack_a->content > *(int *)stack_a->next->content)
				*head = ft_swap(*head, "sa");
			*head = ft_push(head, &stack_b, "pb");
			*head = ft_push(head, &stack_b, "pb");
			break ;
		}
	}
	while (ft_lstsize(stack_b))
		ft_push(&stack_b, head, "pa");
}*/

//bubble sort
/*void	push_swap_large(t_list **head)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = *head;
	stack_b = NULL;
	while (!lst_sorted(stack_a))
	{
		while (stack_a)
		{
			if (!stack_b)
				stack_a = ft_push(&stack_a, &stack_b, "pb");
			else
			{
				if (*(int *)stack_b->content > *(int *)stack_a->content)
				{
					stack_a = ft_push(&stack_a, &stack_b, "pb");
					stack_b = ft_swap(stack_b, "sb");
				}
				else
					stack_a = ft_push(&stack_a, &stack_b, "pb");
			}
		}
		while (stack_b)
		{
			if (!stack_a)
				stack_b = ft_push(&stack_b, &stack_a, "pa");
			else
			{
				if (*(int *)stack_a->content < *(int *)stack_b->content)
				{
					stack_b = ft_push(&stack_b, &stack_a, "pa");
					stack_a = ft_swap(stack_a, "sa");
				}
				else
					stack_b = ft_push(&stack_b, &stack_a, "pa");
			}
		}
	}
}*/

//double bubble
/*void	push_swap_large(t_list **head)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_int_data	a_max_data;	
	t_int_data	b_max_data;
	t_int_data	a_min_data;	
	t_int_data	b_min_data;

	stack_a = *head;
	stack_b = NULL;
	init_list_max(stack_a, &a_max_data);
	init_list_min(stack_a, &a_min_data);
	while (ft_lstsize(stack_a) > ft_lstsize(stack_b))
	{
		if (*(int *)stack_a->content == a_max_data.data
				|| *(int *)stack_a->content == a_min_data.data)
		{
			ft_rotate(&stack_a, "ra");
			continue ;
		}
		stack_a = ft_push(&stack_a, &stack_b, "pb");
	}
	init_list_max(stack_b, &b_max_data);	
	init_list_min(stack_b, &b_min_data);
	while (!lst_sorted(stack_a) || !lst_sorted(stack_b))
	{
		if (*(int *)stack_a->content == a_max_data.data
				&& *(int *)stack_b->content == b_max_data.data)
			rotate_both(&stack_a, &stack_b, "rr");
		else
		{
			if (*(int *)stack_a->content == a_max_data.data)
				ft_rotate(&stack_a, "ra");
			if (*(int *)stack_b->content == b_max_data.data)
				ft_rotate(&stack_b, "rb");
		}
		if (*(int *)stack_a->content > *(int *)stack_a->next->content
				&& *(int *)stack_b->content > *(int *)stack_b->next->content)
			swap_both(&stack_a, &stack_b, "ss");
		else
		{
			if (*(int *)stack_a->content > *(int *)stack_a->next->content)
				stack_a = ft_swap(stack_a, "sa");
			if (*(int *)stack_b->content > *(int *)stack_b->next->content)
				stack_b = ft_swap(stack_b, "sb");
		}
		if (!lst_sorted(stack_a) && !lst_sorted(stack_b))
			rotate_both(&stack_a, &stack_b, "rr");
		else
		{
			if (!lst_sorted(stack_a))
				stack_a = ft_rotate(&stack_a, "ra");
			else if (!lst_sorted(stack_b))
				stack_b = ft_rotate(&stack_b, "rb");
		}
	}
	while (ft_lstsize(stack_b))
	{
		while (ft_lstsize(stack_b)
				&& (*(int *)stack_a->content < *(int *)stack_b->content))
			stack_a = ft_rotate(&stack_a, "ra");
		stack_b = ft_push(&stack_b, &stack_a, "pa");
	}
	while (!lst_sorted(stack_a))
		stack_a = ft_rotate(&stack_a, "ra");
	*head = stack_a;
}*/

/*t_list	*sort_list(t_list **head, t_list **lst)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*tmp;
	int			num;
	t_int_data	max_data;
	t_int_data	min_data;

	stack_a = *lst;
	tmp = *head;
	while (tmp)
	{
		num = *(int *)tmp->content;
		ft_lstadd_back(&stack_a, ft_lstnew(&num, sizeof(int)));
		tmp = tmp->next;
	}
	stack_b = NULL;
	init_list_max(stack_a, &max_data);
	init_list_min(stack_a, &min_data);	
	stack_a = push_min_max(&stack_a, &stack_b, min_data, 0);
	stack_a = push_min_max(&stack_a, &stack_b, max_data, 0);	
	stack_a = ft_push(&stack_a, &stack_b, NULL);
	stack_b = ft_swap(stack_b, NULL);
	while (ft_lstsize(stack_a))
	{
		if (*(int *)stack_b->content > *(int *)stack_a->content)
		{	
			while (ft_lstsize(stack_a) && *(int *)stack_b->content > *(int *)stack_a->content)
				stack_b = ft_rotate(&stack_b, NULL);
			stack_a = ft_push(&stack_a, &stack_b, NULL);
		}
		if (ft_lstsize(stack_a) && *(int *)stack_b->content < *(int *)stack_a->content)
		{	
			while (ft_lstsize(stack_a) && *(int *)stack_b->content < *(int *)stack_a->content) 
				stack_b = ft_rev_rotate(&stack_b, NULL);
			stack_a = ft_push(&stack_a, &stack_b, NULL);
			stack_b = ft_swap(stack_b, NULL);
		}
	}
	init_list_max(stack_b, &max_data);
	if (max_data.loc < ft_lstsize(stack_b) / 2)
	{
		while (*(int *)stack_b->content != max_data.data)
			stack_b = ft_rev_rotate(&stack_b, NULL);
	}
	else
	{
		while (*(int *)stack_b->content != max_data.data)
			stack_b = ft_rotate(&stack_b, NULL);
	}
	while (ft_lstsize(stack_b))
		ft_push(&stack_b, &stack_a, NULL);
	return (stack_a);
}*/

///best to date
/*void	push_swap_large(t_list **head, t_list **tmp)
{
	t_int_data	min_data;
	t_int_data	max_data;
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*comp;
	int			flag;

	stack_a = *head;
	stack_b = NULL;	
	flag = 0;
	make_sorted_list(*head, tmp);
	comp = *tmp;
	comp = ft_rotate(&comp, NULL);
	while (stack_a)
	{
		init_list_min(stack_a, &min_data);
		init_list_max(stack_a, &max_data);
		if (min_data.loc <= ft_lstsize(stack_a) / 2)
		{	
			while (*(int *)stack_a->content != min_data.data)
			{
				if (*(int *)stack_a->content == max_data.data)
				{
					stack_a = ft_push(&stack_a, &stack_b, "pb");
					if (ft_lstsize(stack_b) > 1)
					{
						if (*(int *)stack_a->content != min_data.data)
							rotate_both(&stack_a, &stack_b, "rr");
						else
							stack_b = ft_rotate(&stack_b, "rb");
					}
					init_list_max(stack_a, &max_data);
				}
				else if (*(int *)stack_a->content == *(int *)comp->content)
				{
					stack_a = ft_push(&stack_a, &stack_b, "pb");
					flag = 1;
				}
				else
					stack_a = ft_rotate(&stack_a, "ra");
			}
		}
		else
		{
			while (*(int *)stack_a->content != min_data.data)
			{
				if (*(int *)stack_a->content == max_data.data)
				{
					stack_a = ft_push(&stack_a, &stack_b, "pb");
					if (ft_lstsize(stack_b) > 1)
					{
						if (*(int *)stack_a->content != min_data.data)
							rotate_both(&stack_a, &stack_b, "rr");
						else
							stack_b = ft_rotate(&stack_b, "rb");
					}
					init_list_max(stack_a, &max_data);
				}	
				else
					stack_a = ft_rev_rotate(&stack_a, "rra");
			}
		}
		stack_a = ft_push(&stack_a, &stack_b, "pb");
		comp = ft_rotate(&comp, NULL);
		if (flag)
		{
			stack_b = ft_swap(stack_b, "sb");
			flag = 0;
			comp = ft_rotate(&comp, NULL);
		}
	}
	init_list_max(stack_b, &max_data);
	while (!lst_rev_sorted(stack_b))
	{
		if (max_data.loc <= ft_lstsize(stack_b) / 2)
			stack_b = ft_rotate(&stack_b, "rb");
		else
			stack_b = ft_rev_rotate(&stack_b, "rrb");
	}
	while (stack_b)
		stack_b = ft_push(&stack_b, &stack_a, "pa");	
//	ft_putstr("head: ");
//	ft_lstprint(stack_a, ft_lstprint_int);
//	ft_putchar('\n');
}*/

void	ft_partition(t_list *head, t_list **a, t_list **b)
{
	int		i;

	if (head == NULL || head->next == NULL)
	{
		*a = head;
		*b = NULL;
	}
	else
	{
		i = 0;
		if (ft_lstsize(head) % 2 == 0)
			i = 1;
		*a = head;
		while (i < ft_lstsize(head) / 2)
		{
			head = head->next;
			i++;
		}
		*b = head->next;
		head->next = NULL;
	}
}

t_list	*ft_merge_lists(t_list *a, t_list *b)
{
	t_list	*merged;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (*(int *)a->content <= *(int *)b->content)
	{
		merged = a;
		merged->next = ft_merge_lists(a->next, b);
	}
	else
	{
		merged = b;
		merged->next = ft_merge_lists(a, b->next);
	}
	return (merged);
}

void	ft_merge_sort(t_list **sorting)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *sorting;
	a = NULL;
	b = NULL;
	if (head == NULL || head->next == NULL)
		return ;
	ft_partition(head, &a, &b);
	ft_merge_sort(&a);
	ft_merge_sort(&b);
	*sorting = ft_merge_lists(a, b);
}

void	make_sorted_list(t_list *stack, t_list **sorted, int len)
{
	t_list	*tmp;
	int 	num;
	int		i;
	
	while (len)
	{
		num = *(int *)stack->content;
		ft_lstadd_back(sorted, ft_lstnew(&num, sizeof(int)));
		stack = stack->next;	
		len--;
	}
	ft_merge_sort(sorted);
	i = 0;
	tmp = *sorted;
	while (tmp)
	{
		tmp->location = i++;
		tmp = tmp->next;
	}	
}

void	set_stack_location(t_list *stack, t_list **sorted)
{
	t_list	*reference;

	while (stack)
	{
		reference = *sorted;
		while (reference)
		{
			if (*(int *)stack->content == *(int *)reference->content)
				stack->location = reference->location;
			reference = reference->next;
		}
		stack = stack->next;
	}
}

int		find_pivot(t_list *sorted, int center)
{
	int	i;

	i = 0;
	if (ft_lstsize(sorted) % 2 == 0)
		i = 1;
	while (i < center)
	{
		sorted = sorted->next;
		i++;
	}
	return (*(int *)sorted->content);
}

int	pivot_to_b(t_list **stack_a, t_list **stack_b, t_list *sorted, int pivot)
{
	double	len;
	int		rot;
	t_list	*tmp;

	rot = 0;
	len = (double)ft_lstsize(sorted) / 2;
	while ((double)ft_lstsize(*stack_b) < len)
	{
		tmp = *stack_a;
		if (*(int *)tmp->content <= pivot)
			ft_push(stack_a, stack_b, "pb");
		else
		{
			ft_rotate(stack_a, "ra");
			rot++;
		}
	}
	return (rot);
}

int	pivot_to_a(t_list **stack_a, t_list **stack_b, t_list *sorted, int pivot)
{
	t_list	*tmp;
	int		part_len;
	int		half;

	part_len = 0;
	half = ft_lstsize(sorted) / 2;
	while (part_len < half)
	{
		tmp = *stack_b;
		if (*(int *)tmp->content > pivot)
		{
			ft_push(stack_b, stack_a, "pa");
			part_len++;
		}
		else
			ft_rotate(stack_b, "rb");
	}
	return (part_len);
}

void	sort_stack_b(t_list **stack_a, t_list **stack_b, int next)
{
	t_list	*tmp;
	t_int_data	max;

	while (ft_lstsize(*stack_b))
	{
		tmp = *stack_b;
		init_list_max(tmp, &max);
		if (tmp->location == next)
		{
			ft_push(stack_b, stack_a, "pa");
			ft_rotate(stack_a, "ra");
			next++;
		}
		else if (!max.loc)
			ft_push(stack_b, stack_a, "pa");
		else
			ft_rotate(stack_b, "rb");
	}
}

/*void	push_swap_large(t_list **stack_a, t_list **stack_b)
{
	t_list	*sorted;
	int		pivot;
	t_list	*tmp;

	sorted = NULL;	
	make_sorted_list(*stack_a, &sorted);
	pivot = find_pivot(sorted, ft_lstsize(sorted) / 2);	
	set_stack_location(*stack_a, &sorted);	
	split_stack_a(stack_a, stack_b, pivot);
	sort_stack_b(stack_a, stack_b, 0);
	tmp = *stack_a;	
	while (tmp->location != 0)
	{
		if (tmp->location == ft_lstlast(*stack_a)->location + 1)
			ft_rotate(stack_a, "ra");
		else
			ft_push(stack_a, stack_b, "pb");
		tmp = *stack_a;
	}
	sort_stack_b(stack_a, stack_b, ft_lstlast(*stack_a)->location);
	tmp = *stack_a;
	while (tmp->location != 0)
	{
		tmp = *stack_a;
		ft_rotate(stack_a, "ra");
	}
	ft_rev_rotate(stack_a, "rra");
	ft_lstclear(&sorted, ft_free);
}*/

void	TMPpush_min_max(t_list **src, t_list **dest, t_int_data int_data)
{
	t_list	*stack;

	stack = *src;
	if ((double)int_data.loc >= (double)ft_lstsize(stack) / 2.0)
	{		
		while (*(int *)stack->content != int_data.data)
		{	
			ft_rev_rotate(src, "rrb");
			stack = *src;
		}
	}
	else
	{	
		while (*(int *)stack->content != int_data.data)
		{	
			ft_rotate(src, "rb");
			stack = *src;
		}
	}
//	if (!lst_sorted(*src))
	ft_push(src, dest, "pa");
}

void	TMP_push_swap_three(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	if (lst_rev_sorted(*head))
	{
		*head = ft_swap(*head, "sb");
		ft_rev_rotate(head, "rrb");
	}
	else if (head_is_max(*head))
		ft_rotate(head, "rb");
	else if (head_is_mid(*head) && *(int *)tmp->next->content
			< *(int *)ft_lstlast(*head)->content)
		*head = ft_swap(*head, "sb");
	else if (head_is_mid(*head))
		ft_rev_rotate(head, "rrb");
	if (!lst_sorted(*head))
	{	
		*head = ft_swap(*head, "sb");
		ft_rotate(head, "rb");
	}
}

void	TMP_push_swap_small(t_list **head, t_list **tool, int len)
{
	t_int_data	min_data;

	init_list_min(*head, &min_data);
	TMPpush_min_max(head, tool, min_data);	
	if (len == 5)
	{
		init_list_min(*head, &min_data);
		TMPpush_min_max(head, tool, min_data);
	}
	TMP_push_swap_three(head);
	if (len == 4 || len == 5)
		ft_push(tool, head, "pb");
	if (len == 5)
		ft_push(tool, head, "pb");
}

void	please_work(t_list **stack_a, t_list **stack_b)
{
	t_int_data	min_data;
	t_int_data	max_data;
	t_list		*tmp;
	int			last;

	init_list_max(*stack_b, &max_data);
	last = max_data.data;
	while (*stack_b)
	{
		tmp = *stack_b;
		init_list_min(*stack_b, &min_data);
		init_list_max(*stack_b, &max_data);
		if (*(int *)tmp->content == min_data.data)
		{
			ft_push(stack_b, stack_a, "pa");
			tmp = *stack_b;
/*			if (*(int *)tmp->content != max_data.data 
					&& (double)max_data.loc < (double)ft_lstsize(*stack_b) / 2)
				rotate_both(stack_a, stack_b, "rr");*/
//			else
			ft_rotate(stack_a, "ra");
		}
		else if (*(int *)tmp->content == max_data.data)
			ft_push(stack_b, stack_a, "pa");
		else if ((double)max_data.loc < (double)ft_lstsize(*stack_b) / 2)
			ft_rotate(stack_b, "rb");
		else
			ft_rev_rotate(stack_b, "rrb");
	}
	tmp = *stack_a;
	while (*(int *)ft_lstlast(tmp)->content != last)
	{
		ft_rotate(stack_a, "ra");
		tmp = *stack_a;
	}
}

void	change_later(t_list **stack_a, t_list **stack_b, int len)
{
	t_list	*tmp;

	tmp = *stack_b;
	len = 0;
/*	if (len == 2 && *(int *)tmp->content > *(int *)tmp->next->content)
		*stack_b = ft_swap(*stack_b, "sb");
	else if (len == 3 && !lst_sorted(*stack_b))
		TMP_push_swap_three(stack_b);
	else if (!lst_sorted(*stack_b) && (len == 4 || len == 5))
		TMP_push_swap_small(stack_b, stack_a, len);
	else if (len > 3 && !lst_sorted(*stack_b))*/
	please_work(stack_a, stack_b);
/*	while (*stack_b)
	{
		ft_push(stack_b, stack_a, "pa");
		ft_rotate(stack_a, "ra");	
	}	*/
}

void	partition_stack(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*sorted;
	t_list	*tmp;
	int		pivot;
	int		rot;
	int		s_len;
	int		p_len;

	sorted = NULL;
	if (!info->part_len && !info->stack_len)
		p_len = ft_lstsize(*stack_a);	
	else if (!info->part_len)
	{
		p_len = *(int *)info->stack_len->content;
		if (ft_lstsize(info->stack_len) > 1)
			ft_rotate(&info->stack_len, NULL);
	}
	else
	{
		p_len = info->part_len;
		info->part_len = 0;
	}
	if (p_len >= 1 && p_len <= 21)
	{
		while (p_len)
		{
			tmp = *stack_a;
			if (tmp->location == ft_lstlast(tmp)->location + 1)
				ft_rotate(stack_a, "ra");
			else
				ft_push(stack_a, stack_b, "pb");
			p_len--;
		}
	}
	else
	{
		make_sorted_list(*stack_a, &sorted, p_len);
		pivot = find_pivot(sorted, ft_lstsize(sorted) / 2);
		rot = pivot_to_b(stack_a, stack_b, sorted, pivot);
		while (rot)
		{
			if (!info->stack_len)
				break ;
			ft_rev_rotate(stack_a, "rra");
			rot--;
		}
		s_len = ft_lstsize(sorted) / 2;	
		ft_lstadd_front(&info->stack_len, ft_lstnew(&s_len, sizeof(int)));	
	}
	ft_lstclear(&sorted, ft_free);
}

void	partition_part(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*sorted;
	int		pivot;
	int		len;

	sorted = NULL;
	make_sorted_list(*stack_b, &sorted, ft_lstsize(*stack_b));
	pivot = find_pivot(sorted, ft_lstsize(sorted) / 2);
	len = pivot_to_a(stack_a, stack_b, sorted, pivot);
	if (len <= 21)
		info->part_len = len;
	else
		ft_lstadd_front(&info->stack_len, ft_lstnew(&len, sizeof(int)));
	ft_lstclear(&sorted, ft_free);
}

void	push_swap_large(t_list **stack_a, t_list **stack_b, t_info *info)
{
/*	if (info->stack_len)
	{
		ft_putendl("info->stack_len: ");
		ft_lstprint(info->stack_len, ft_lstprint_int);
		ft_putchar('\n');
	}*/
	if (*stack_b && ft_lstsize(*stack_b) <= 21)
		change_later(stack_a, stack_b, ft_lstsize(*stack_b));
	if (!*stack_b && !lst_sorted(*stack_a))
		partition_stack(stack_a, stack_b, info);
	if (*stack_b && ft_lstsize(*stack_b) > 21)
		partition_part(stack_a, stack_b, info);
	if (*stack_b || !lst_sorted(*stack_a))
		push_swap_large(stack_a, stack_b, info);
}

void	push_swap(int lst_size, t_list **head)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*sorted;
//	t_list	*tmp;
	t_info	info;

	stack_a = *head;
	stack_b = NULL;
	sorted = NULL;	
//	tmp = NULL;
	info.stack_len = NULL;
	info.part_len = 0;
	if (lst_size == 2 && *(int *)stack_a->content
		> *(int *)stack_a->next->content)
		ft_swap(stack_a, "sa");
	else if (lst_size == 3)
		push_swap_three(head);
	else if (lst_size == 4 || lst_size == 5)
		push_swap_small(head, &stack_b);
	else
	{
		make_sorted_list(*head, &sorted, ft_lstsize(*head));
		set_stack_location(*head, &sorted);
		ft_lstclear(&sorted, ft_free);
		push_swap_large(head, &stack_b, &info);
	}
	if (info.stack_len)
		ft_lstclear(&info.stack_len, ft_free);
}

void	create_list(t_list **head, int i, int flag, char **argv)
{
	int		num;
	t_list	*tmp;

	while (argv[i])
	{
		overflow_check(ft_atoi(argv[i]), argv[i], *head);
		num = ft_atoi(argv[i]);
		if (flag)
			ft_free(argv[i]);
		i++;
		ft_lstadd_back(head, ft_lstnew(&num, sizeof(int)));
		tmp = *head;
		tmp->location = 0;
	}
	if (flag)
		ft_free(argv);
	duplicate_check(*head);
}

int	main(int argc, char **argv)
{
	int				i;
	t_list			*stack_a;
	int				flag;

	i = 1;
	flag = 0;
	if (argc > 1000) //change later if argc > limit
		failed_exit("Error");
	if (argc == 2 && ft_strchr(argv[i], ' '))
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		flag++;
	}
	if (argc > 1)
	{
		create_list(&stack_a, i, flag, argv);
		if (ft_lstsize(stack_a) > 1 && !lst_sorted(stack_a))
			push_swap(ft_lstsize(stack_a), &stack_a);
//		ft_lstprint(stack_a, ft_lstprint_int);
//		ft_putchar('\n');
		ft_lstclear(&stack_a, ft_free);	
	}
//	system("leaks push_swap");
	exit(EXIT_SUCCESS);
}
