#include "../../libft/libft.h"
#include "../../includes/checker.h"

void	free_and_exit(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		ft_lstclear(stack_a, ft_free);
	if (*stack_b)
		ft_lstclear(stack_b, ft_free);
	ft_failed_exit("Error", NULL);
}
