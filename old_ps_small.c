
/*t_list	*push_swap_four(t_list **head)
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
	return (*head);
}

void	push_swap_five(t_list **head)
{
	t_list	*stack_a;

	stack_a = *head;
	if (*(int *)stack_a->content > *(int *)ft_lstlast(stack_a)->content)
		ft_rotate(head, "ra");
	else if (*(int *)stack_a->content
			> *(int *)stack_a->next->next->next->content)
	{	
		ft_rev_rotate(head, "rra");
		ft_swap(*head, "sa");
		ft_rotate(head, "ra");
		ft_rotate(head, "ra");
	}
	else if (*(int *)stack_a->content > *(int *)stack_a->next->next->content)
	{
		ft_swap(*head, "sa");
		ft_rotate(head, "ra");
		ft_swap(*head, "sa");
		ft_rev_rotate(head, "rra");
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
	if ((ft_lstsize(stack_a) == 4 && !lst_sorted(stack_a->next))
			|| (ft_lstsize(stack_a) == 5 && !lst_sorted(stack_a->next)))
	{
		stack_a = ft_push(head, &stack_b, "pb");
		if (ft_lstsize(stack_a) == 4 && !lst_sorted(stack_a->next))
			stack_a = ft_push(head, &stack_b, "pb");
		if (ft_lstsize(stack_a) == 3)
		{	
			stack_a = push_swap_three(head);
			stack_b = ft_push(&stack_b, head, "pa");
			stack_a = *head;
		}
	}
	if (ft_lstsize(stack_a) == 4 && !lst_sorted(stack_a))	
		stack_a = push_swap_four(head);
	if (ft_lstsize(stack_b) == 1)
		ft_push(&stack_b, head, "pa");
	if (ft_lstsize(*head) == 5 && !lst_sorted(*head))
		push_swap_five(head);
}*/
