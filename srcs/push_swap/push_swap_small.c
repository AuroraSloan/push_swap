#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

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
