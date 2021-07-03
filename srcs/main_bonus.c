#include "../libft/libft.h"
#include "../includes/checker.h"

static int	operation_matches(char *operation, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(operation, line, ft_strlen(line)) == 0)
		ret = 1;
	return (ret);
}

static void	emplement_operation(t_list **stack_a, t_list **stack_b, char *line)
{
	if (operation_matches("rr", line) && ft_strlen(line) == 2)
		rotate_both(stack_a, stack_b, NULL);
	else if (operation_matches("ss", line) && ft_strlen(line) == 2)
		swap_both(stack_a, stack_b, NULL);
	else if (operation_matches("sa", line) && ft_strlen(line) == 2)
		ft_swap(*stack_a, NULL);
	else if (operation_matches("sb", line) && ft_strlen(line) == 2)
		ft_swap(*stack_b, NULL);
	else if (operation_matches("ra", line) && ft_strlen(line) == 2)
		ft_rotate(stack_a, NULL);
	else if (operation_matches("rb", line) && ft_strlen(line) == 2)
		ft_rotate(stack_b, NULL);
	else if (operation_matches("pb", line) && ft_strlen(line) == 2)
		ft_push(stack_a, stack_b, NULL);
	else if (operation_matches("pa", line) && ft_strlen(line) == 2)
		ft_push(stack_b, stack_a, NULL);
	else if (operation_matches("rrr", line) && ft_strlen(line) == 3)
		rev_rotate_both(stack_a, stack_b, NULL);
	else if (operation_matches("rra", line) && ft_strlen(line) == 3)
		ft_rev_rotate(stack_a, NULL);
	else if (operation_matches("rrb", line) && ft_strlen(line) == 3)
		ft_rev_rotate(stack_b, NULL);
	else
		free_and_exit(stack_a, stack_b);
}

static void	ft_checker(t_list **head)
{
	t_list	*stack_b;
	char	*line;
	int		ret;
	int		flag;

	stack_b = NULL;
	line = NULL;
	ret = 1;
	flag = 0;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		flag = check_for_nl(flag, line, head);
		if (!ret)
			break ;
		emplement_operation(head, &stack_b, line);
		ft_free(line);
	}
	if (!*head || stack_b)
		ft_putendl("KO");
	else if (lst_sorted(*head))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free(line);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	int		flag;

	i = 1;
	flag = 0;
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
		ft_checker(&stack_a);
	}
	ft_lstclear(&stack_a, ft_free);
	exit(EXIT_SUCCESS);
}
