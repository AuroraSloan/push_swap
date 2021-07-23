#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

static int	calculate_part_len(t_list **stack_a, t_info *info)
{
	int	p_len;

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
	return (p_len);
}

static void	push_to_b(t_list **stack_a, t_list **stack_b, int p_len)
{
	t_list	*tmp;
	int		nxt;
	int		nxt_nxt;

	while (p_len)
	{
		tmp = *stack_a;
		nxt = ft_lstlast(tmp)->location + 1;
		nxt_nxt = ft_lstlast(tmp)->location + 2;
		if (lst_sorted(*stack_a))
			break ;
		if (tmp->location == 0 || tmp->location == nxt)
			ft_rotate(stack_a, "ra");
		else if (tmp->location == nxt_nxt && tmp->next->location == nxt)
		{
			ft_swap(*stack_a, "sa");
			ft_rotate(stack_a, "ra");
			ft_rotate(stack_a, "ra");
			p_len--;
		}
		else
			ft_push(stack_a, stack_b, "pb");
		p_len--;
	}
}

static void	minimize_revrot_instruction(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (tmp->location < ft_lstlast(tmp)->location)
		rev_rotate_both(stack_a, stack_b, "rrr");
	else
		ft_rev_rotate(stack_a, "rra");
}

void	partition_stack(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*sorted;
	int		rot;
	int		s_len;
	int		p_len;

	sorted = NULL;
	p_len = calculate_part_len(stack_a, info);
	if (p_len <= info->sort_by)
		push_to_b(stack_a, stack_b, p_len);
	else
	{
		make_sorted_list(*stack_a, &sorted, p_len);
		rot = pivot_to_b(stack_a, stack_b, sorted);
		while (rot)
		{
			if (!info->stack_len)
				break ;
			minimize_revrot_instruction(stack_a, stack_b);
			rot--;
		}
		s_len = ft_lstsize(sorted) / 2;
		ft_lstadd_front(&info->stack_len, ft_lstnew(&s_len, sizeof(int)));
	}
	ft_lstclear(&sorted, ft_free);
}
