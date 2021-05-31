/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:43:58 by jthompso          #+#    #+#             */
/*   Updated: 2021/05/31 23:43:08 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

void	ft_swap(t_list *lst)
{
	t_list	tmp;

	tmp.next = NULL;
	tmp.content = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp.content;
}

void	ft_rotate(t_list **head, t_list *lst)
{
	t_list	*new_end;

	new_end = lst;
	ft_lstadd_back(&lst, lst);
	*head = lst->next;
	new_end->next = NULL;
}

void	ft_rev_rotate(t_list **head, t_list *lst)
{
	t_list	*new_head;

	new_head = ft_lstlast(*head);
	while (lst->next != new_head)
		lst = lst->next;
	lst->next = NULL;
	ft_lstadd_front(head, new_head);
}

int	list_sorted(t_list *lst)
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
	if (argc > 2)
	{
		while (i < argc)
		{
			num = ft_atoi(argv[i++]);
			ft_lstadd_back(&stack_a, ft_lstnew(&num, data_size));
		}
		duplicate_check(stack_a);
		//while(!list_sorted(stack_a));
		//	push_swap;
		ft_lstprint(stack_a, ft_lstprint_int);
		ft_lstclear(&stack_a, ft_free);
	}
//	system("leaks push_swap");
	exit(EXIT_SUCCESS);
}
