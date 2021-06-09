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

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

t_list	*ft_swap(t_list *lst, char *operation)
{
	t_list	tmp;

	tmp.next = NULL;
	tmp.content = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp.content;
	ft_putendl(operation);
	return (lst);
}

t_list	*ft_rotate(t_list **head, char *operation)
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
	return (*head);
}

t_list	*ft_rev_rotate(t_list **head, char *operation)
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
	return (*head);
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

t_list	*ft_push(t_list **src, t_list **dest, char *operation)
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
	return (*src);
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

t_list	*push_min_max(t_list **src, t_list **dest, t_int_data int_data)
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
		stack = ft_push(src, dest, "pb");
	return (stack);
}

void	push_swap_small(t_list **head)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_int_data	int_data;

	stack_a = *head;
	stack_b = NULL;
	init_list_min(stack_a, &int_data);
	stack_a = push_min_max(head, &stack_b, int_data);
	if (ft_lstsize(stack_a) == 4)
	{	
		init_list_min(stack_a, &int_data);
		stack_a = push_min_max(head, &stack_b, int_data);
	}
	stack_a = push_swap_three(head);
	if (ft_lstsize(stack_b) == 2)
		ft_push(&stack_b, head, "pa");
	if (ft_lstsize(stack_b) == 1)
		ft_push(&stack_b, head, "pa");
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

void	push_swap_large(t_list **head)
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
			//&& *(int *)ft_lstlast(stack_b)->content != max_data.data)
			while (ft_lstsize(stack_a) && *(int *)stack_b->content > *(int *)stack_a->content)
				stack_b = ft_rotate(&stack_b, "rb");
			*head = ft_push(&stack_a, &stack_b, "pb");
		}
		if (ft_lstsize(stack_a) && *(int *)stack_b->content < *(int *)stack_a->content)
		{
			//&& *(int *)ft_lstlast(stack_b)->content != min_data.data)
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
}


void	push_swap(int lst_size, t_list **head)
{
	t_list	*stack_a;

	stack_a = *head;
	if (lst_size == 2 && *(int *)stack_a->content
		> *(int *)stack_a->next->content)
		ft_swap(stack_a, "sa");
	else if (lst_size == 3)
		push_swap_three(head);
	else if (lst_size == 4 || lst_size == 5)
		push_swap_small(head);
	else
		push_swap_large(head);
}

void	create_list(t_list **head, int i, int flag, char **argv)
{
	int		num;

	while (argv[i])
	{
		overflow_check(ft_atoi(argv[i]), argv[i], *head);
		num = ft_atoi(argv[i]);
		if (flag)
			ft_free(argv[i]);
		i++;
		ft_lstadd_back(head, ft_lstnew(&num, sizeof(int)));
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
	if (argc > 501) //change later if argc > limit
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
		ft_lstclear(&stack_a, ft_free);
	}
	exit(EXIT_SUCCESS);
}
