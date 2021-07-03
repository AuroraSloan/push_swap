#include "../libft/libft.h"
#include "../includes/push_swap.h"

int	find_pivot(t_list *sorted, int center)
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

static void	partition_part(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*sorted;
	int		pivot;
	int		len;

	sorted = NULL;
	make_sorted_list(*stack_b, &sorted, ft_lstsize(*stack_b));
	pivot = find_pivot(sorted, ft_lstsize(sorted) / 2);
	len = pivot_to_a(stack_a, stack_b, sorted, pivot);
	if (ft_lstsize(*stack_b) <= info->sort_by)
		info->part_len = len;
	else
		ft_lstadd_front(&info->stack_len, ft_lstnew(&len, sizeof(int)));
	ft_lstclear(&sorted, ft_free);
}

void	push_swap_large(t_list **stack_a, t_list **stack_b, t_info *info)
{
	if (*stack_b && ft_lstsize(*stack_b) <= info->sort_by)
		sort_to_a(stack_a, stack_b);
	if (!*stack_b && !lst_sorted(*stack_a))
		partition_stack(stack_a, stack_b, info);
	if (*stack_b && ft_lstsize(*stack_b) > info->sort_by)
		partition_part(stack_a, stack_b, info);
	if (*stack_b || !lst_sorted(*stack_a))
		push_swap_large(stack_a, stack_b, info);
	if (info->stack_len)
		ft_lstclear(&info->stack_len, ft_free);
}
