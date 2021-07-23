#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

static void	ms_partition(t_list *head, t_list **a, t_list **b)
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

static t_list	*ms_merge_lists(t_list *a, t_list *b)
{
	t_list	*merged;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (*(int *)a->content <= *(int *)b->content)
	{
		merged = a;
		merged->next = ms_merge_lists(a->next, b);
	}
	else
	{
		merged = b;
		merged->next = ms_merge_lists(a, b->next);
	}
	return (merged);
}

static void	ft_merge_sort(t_list **sorting)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *sorting;
	a = NULL;
	b = NULL;
	if (head == NULL || head->next == NULL)
		return ;
	ms_partition(head, &a, &b);
	ft_merge_sort(&a);
	ft_merge_sort(&b);
	*sorting = ms_merge_lists(a, b);
}

void	make_sorted_list(t_list *stack, t_list **sorted, int len)
{
	t_list	*tmp;
	int		num;
	int		i;

	while (len)
	{
		num = *(int *)stack->content;
		ft_lstadd_back(sorted, ft_lstnew(&num, sizeof(int)));
		stack = stack->next;
		len--;
	}
	ft_merge_sort(sorted);
	i = 0;
	tmp = *sorted;
	while (tmp)
	{
		tmp->location = i++;
		tmp = tmp->next;
	}	
}
