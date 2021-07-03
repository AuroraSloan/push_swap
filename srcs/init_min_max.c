#include "../libft/libft.h"
#include "../includes/push_swap.h"

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
