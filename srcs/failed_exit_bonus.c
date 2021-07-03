#include "../libft/libft.h"
#include "../includes/checker.h"

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

void	free_and_exit(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		ft_lstclear(stack_a, ft_free);
	if (*stack_b)
		ft_lstclear(stack_b, ft_free);
	failed_exit("Error");
}

int	check_for_nl(int flag, char *line, t_list **head)
{
	int	ret;

	ret = 0;
	if (flag && line[0] == '\n')
	{
		ft_free(line);
		ft_lstclear(head, ft_free);
		failed_exit("Error");
	}
	else if (!flag && line[0] == '\n')
		ret = 1;
	return (ret);
}
