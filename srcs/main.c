/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:43:58 by jthompso          #+#    #+#             */
/*   Updated: 2021/06/02 22:32:52 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <limits.h>

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

void	ft_swap(t_list *lst, char *operation)
{
	t_list	tmp;

	tmp.next = NULL;
	tmp.content = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp.content;
	ft_putendl(operation);
}

void	ft_rotate(t_list **head, t_list *lst, char *operation)
{
	t_list	*new_end;

	new_end = lst;
	ft_lstadd_back(&lst, lst);
	*head = lst->next;
	new_end->next = NULL;
	ft_putendl(operation);
}

void	ft_rev_rotate(t_list **head, t_list *lst, char *operation)
{
	t_list	*new_head;

	new_head = ft_lstlast(*head);
	while (lst->next != new_head)
		lst = lst->next;
	lst->next = NULL;
	ft_lstadd_front(head, new_head);
	ft_putendl(operation);
}

int	lst_sorted(t_list *lst)
{
	int	ret;

	ret = 1;
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
		{
			ret = 0;
			break ;
		}
		lst = lst->next;
	}
	return (ret);
}

int	lst_rev_sorted(t_list *lst)
{
	int	ret;

	ret = 1;
	while (lst->next)
	{
		if (*(int *)lst->content < *(int *)lst->next->content)
		{
			ret = 0;
			break ;
		}
		lst = lst->next;
	}
	return (ret);
}

void	duplicate_check(t_list *lst)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(int *)lst->content == *(int *)tmp->content)
			{
				ft_lstclear(&lst, ft_free);
				failed_exit("Error");
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void	overflow_check(int num, char *str, t_list *lst)
{
	char	*revert;

	revert = ft_itoa(num);
	if (ft_memcmp(revert, str, ft_strlen(str)) != 0)
	{
		ft_free(revert);
		ft_lstclear(&lst, ft_free);
		failed_exit("Error");
	}
	ft_free(revert);
}

int	head_is_max(t_list *lst)
{
	return (*(int *)lst->content > *(int *)lst->next->content
		&& *(int *)lst->content > *(int *)ft_lstlast(lst)->content);
}

int	head_is_mid(t_list *lst)
{
	if (*(int *)lst->content > *(int *)lst->next->content
		&& *(int *)lst->content < *(int *)ft_lstlast(lst)->content)
		return (1);
	if (*(int *)lst->content < *(int *)lst->next->content
		&& *(int *)lst->content > *(int *)ft_lstlast(lst)->content)
		return (1);
	return (0);
}

void	push_swap_three(t_list **head, t_list *stack_a)
{
	if (lst_rev_sorted(stack_a))
	{
		ft_swap(stack_a, "sa");
		ft_rev_rotate(head, stack_a, "rra");
	}
	else if (head_is_max(stack_a))
		ft_rotate(head, stack_a, "ra");
	else if (head_is_mid(stack_a) && *(int *)stack_a->next->content
		< *(int *)ft_lstlast(stack_a)->content)
		ft_swap(stack_a, "sa");
	else if (head_is_mid(stack_a))
		ft_rev_rotate(head, stack_a, "rra");
	else if (!lst_sorted(stack_a))
	{
		ft_swap(stack_a, "sa");
		ft_rotate(head, stack_a, "ra");
	}
}

void	*ft_lstpop(t_list **head, t_list *lst/*, void (*del)(void*)*/)
{
	void	*ptr;
//	t_list	*delete;

	//if (!head || !del)
	//	return ;
//	delete = lst;
	ptr = lst->content;	
	*head = lst->next;
//	ft_lstdelone(delete, del);	
//	new_head = (*head)->content;	
//	ft_lstadd_front(head, new_head);
	return (ptr);
}

void	ft_push(t_list **head, t_list *stack_a, t_list **dest, char *operation)
{
	int		data_size;
	void	*pop;

	*head = stack_a->next;
	data_size = sizeof(int);
	pop = ft_lstpop(head, stack_a);
	ft_lstadd_front(dest, ft_lstnew(pop, data_size));
	ft_putendl(operation);
}

void	push_swap_small(t_list *stack_a)
{	
	t_list *stack_b;

	stack_b = NULL;
	ft_push(&stack_a, stack_a, &stack_b, "pb");
	ft_push(&stack_a, stack_a, &stack_b, "pb");
	ft_lstprint(stack_a, ft_lstprint_int);
	ft_putchar('\n');
	ft_lstprint(stack_b, ft_lstprint_int);
	ft_putchar('\n');
	ft_lstclear(&stack_b, ft_free);
}

void	push_swap(int argc, t_list **head, t_list *stack_a)
{	
	if (argc == 3 && *(int *)stack_a->content > *(int *)stack_a->next->content)
		ft_swap(stack_a, "SA");
	else if (argc == 4)
		push_swap_three(head, stack_a);
	else if (argc == 5 || argc == 6)
		push_swap_small(stack_a);	
}

int	main(int argc, char **argv)
{
	int				i;
	int				num;
	t_list			*stack_a;
	unsigned int	data_size;

	i = 1;
	data_size = sizeof(int);
	if (argc > 501) //change later if argc > limit
		failed_exit("Error");
	while (i < argc)
	{
		overflow_check(ft_atoi(argv[1]), argv[1], stack_a);
		num = ft_atoi(argv[i++]);
		ft_lstadd_back(&stack_a, ft_lstnew(&num, data_size));
	}
	duplicate_check(stack_a);	
	if (argc > 2)
		push_swap(argc, &stack_a, stack_a);
	ft_lstprint(stack_a, ft_lstprint_int);
	ft_lstclear(&stack_a, ft_free);
	system("leaks push_swap");
	exit(EXIT_SUCCESS);
}
