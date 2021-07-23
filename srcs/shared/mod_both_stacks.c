#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

void	swap_both(t_list **stack_a, t_list **stack_b, char *operation)
{
	ft_swap(*stack_a, NULL);
	ft_swap(*stack_b, NULL);
	if (operation)
		ft_putendl(operation);
}

void	rotate_both(t_list **stack_a, t_list **stack_b, char *operation)
{
	ft_rotate(stack_a, NULL);
	ft_rotate(stack_b, NULL);
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
