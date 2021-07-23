#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

static void	min_to_a(t_list **stack_a, t_list **stack_b, t_int_data max_data)
{
	int		half;
	t_list	*tmp;

	half = (double)ft_lstsize(*stack_b) / 2;
	ft_push(stack_b, stack_a, "pa");
	tmp = *stack_b;
	if (*(int *)tmp->content != max_data.data && (double)max_data.loc < half)
		rotate_both(stack_a, stack_b, "rr");
	else
		ft_rotate(stack_a, "ra");
}

static void	rotate_srtd_lst(t_list **stack_a, int last)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (*(int *)ft_lstlast(tmp)->content != last)
	{
		ft_rotate(stack_a, "ra");
		tmp = *stack_a;
	}
}

void	sort_to_a(t_list **stack_a, t_list **stack_b)
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
		if (*(int *)tmp->content == min_data.data && ft_lstsize(*stack_b) > 1)
			min_to_a(stack_a, stack_b, max_data);
		else if (*(int *)tmp->content == max_data.data)
			ft_push(stack_b, stack_a, "pa");
		else if ((double)max_data.loc < (double)ft_lstsize(*stack_b) / 2)
			ft_rotate(stack_b, "rb");
		else
			ft_rev_rotate(stack_b, "rrb");
	}
	rotate_srtd_lst(stack_a, last);
}
