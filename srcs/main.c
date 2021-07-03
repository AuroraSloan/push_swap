#include "../libft/libft.h"
#include "../includes/push_swap.h"

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

static void	set_stack_location(t_list *stack, t_list **sorted)
{
	t_list	*reference;

	while (stack)
	{
		reference = *sorted;
		while (reference)
		{
			if (*(int *)stack->content == *(int *)reference->content)
				stack->location = reference->location;
			reference = reference->next;
		}
		stack = stack->next;
	}
}

static void	push_swap(int lst_size, t_list **head, t_info *info)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*sorted;

	stack_a = *head;
	stack_b = NULL;
	sorted = NULL;
	if (lst_size == 2 && *(int *)stack_a->content
		> *(int *)stack_a->next->content)
		ft_swap(stack_a, "sa");
	else if (lst_size == 3)
		push_swap_three(head);
	else if (lst_size == 4 || lst_size == 5)
		push_swap_small(head, &stack_b);
	else
	{
		if (ft_lstsize(*head) >= 250)
			info->sort_by = 16;
		else
			info->sort_by = 13;
		make_sorted_list(*head, &sorted, ft_lstsize(*head));
		set_stack_location(*head, &sorted);
		ft_lstclear(&sorted, ft_free);
		push_swap_large(head, &stack_b, info);
	}
}

static void	create_list(t_list **head, int i, int flag, char **argv)
{
	int		num;
	t_list	*tmp;

	while (argv[i])
	{
		overflow_check(ft_atoi(argv[i]), argv[i], *head);
		num = ft_atoi(argv[i]);
		if (flag)
			ft_free(argv[i]);
		i++;
		ft_lstadd_back(head, ft_lstnew(&num, sizeof(int)));
		tmp = *head;
		tmp->location = 0;
	}
	if (flag)
		ft_free(argv);
	duplicate_check(*head);
}

int	main(int argc, char **argv)
{
	int		i;
	int		flag;
	t_list	*stack_a;
	t_info	info;

	i = 1;
	flag = 0;
	info.stack_len = NULL;
	info.part_len = 0;
	stack_a = NULL;
	if (argc > 1000)
		failed_exit("Error");
	if (argc == 2 && ft_strchr(argv[i], ' '))
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		flag++;
	}
	if (argc > 1)
	{
		create_list(&stack_a, i, flag, argv);
		if (ft_lstsize(stack_a) > 1 && !lst_sorted(stack_a))
			push_swap(ft_lstsize(stack_a), &stack_a, &info);
		ft_lstclear(&stack_a, ft_free);
	}
	exit(EXIT_SUCCESS);
}
