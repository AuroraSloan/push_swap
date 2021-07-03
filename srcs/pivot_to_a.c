#include "../libft/libft.h"
#include "../includes/push_swap.h"

static void	push_nxt_to_a(t_list **stack_a, t_list **stack_b, int pivot)
{
	t_list	*tmp;

	ft_push(stack_b, stack_a, "pa");
	tmp = *stack_b;
	if (*(int *)tmp->content <= pivot)
		rotate_both(stack_a, stack_b, "rr");
	else
		ft_rotate(stack_a, "ra");
}

int	pivot_to_a(t_list **stack_a, t_list **stack_b, t_list *sorted, int pivot)
{
	t_list	*tmp;
	int		part_len;
	int		half;
	int		nxt;

	part_len = 0;
	half = ft_lstsize(sorted) / 2;
	nxt = ft_lstlast(*stack_a)->location + 1;
	while (part_len < half)
	{
		tmp = *stack_b;
		if (*(int *)tmp->content > pivot)
		{
			ft_push(stack_b, stack_a, "pa");
			part_len++;
		}
		else if (tmp->location == 0 || tmp->location == nxt)
			push_nxt_to_a(stack_a, stack_b, pivot);
		else
			ft_rotate(stack_b, "rb");
	}
	return (part_len);
}
