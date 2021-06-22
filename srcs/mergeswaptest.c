#include "../libft/libft.h"
#include "../includes/push_swap.h"

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

void	ft_partition(t_list *head, t_list **a, t_list **b)
{
	int		i;

	if (head == NULL || head->next == NULL)
	{
		*a = head;
		*b = NULL;
	}
	else
	{
		i = 0;
		if (ft_lstsize(head) % 2 == 0)
			i = 1;
		*a = head;
		while (i < ft_lstsize(head) / 2)
		{
			head = head->next;
			i++;
		}
		*b = head->next;
		head->next = NULL;
	}
}

t_list	*ft_merge_lists(t_list *a, t_list *b)
{
	t_list	*merged;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (*(int *)a->content <= *(int *)b->content)
	{
		merged = a;
		merged->next = ft_merge_lists(a->next, b);
	}
	else
	{
		merged = b;
		merged->next = ft_merge_lists(a, b->next);
	}
	return (merged);
}

void	ft_merge_sort(t_list **sorting)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *sorting;
	a = NULL;
	b = NULL;
	if (head == NULL || head->next == NULL)
		return ;
	ft_partition(head, &a, &b);
	ft_merge_sort(&a);
	ft_merge_sort(&b);
	*sorting = ft_merge_lists(a, b);
}

void	create_list(t_list **head, int i, int flag, char **argv)
{
	int		num;

	while (argv[i])
	{	
		num = ft_atoi(argv[i]);
		if (flag)
			ft_free(argv[i]);
		i++;
		ft_lstadd_back(head, ft_lstnew(&num, sizeof(int)));
	}
	if (flag)
		ft_free(argv);	
}

int	main(int argc, char **argv)
{
	int				i;
	t_list			*stack_a;
	int				flag;

	i = 1;
	flag = 0;
	if (argc > 501) //change later if argc > limit
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
		ft_merge_sort(&stack_a);
		ft_lstclear(&stack_a, ft_free);
	}
	system("leaks a.out");
	exit(EXIT_SUCCESS);
}
