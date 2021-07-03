#include "../libft/libft.h"
#include "../includes/push_swap.h"

static void	minimize_rot_instruction(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (ft_lstsize(*stack_b) > 1 && tmp->location < tmp->next->location)
		rotate_both(stack_a, stack_b, "rr");
	else
		ft_rotate(stack_a, "ra");
}

int	pivot_to_b(t_list **stack_a, t_list **stack_b, t_list *sorted)
{
	double	len;
	int		rot;
	int		pivot;
	t_list	*tmp;

	rot = 0;
	len = (double)ft_lstsize(sorted) / 2;
	pivot = find_pivot(sorted, ft_lstsize(sorted) / 2);
	while ((double)ft_lstsize(*stack_b) < len)
	{
		tmp = *stack_a;
		if (*(int *)tmp->content <= pivot)
			ft_push(stack_a, stack_b, "pb");
		else
		{
			minimize_rot_instruction(stack_a, stack_b);
			rot++;
		}
	}
	return (rot);
}
