/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:32:31 by jthompso          #+#    #+#             */
/*   Updated: 2021/06/09 18:20:46 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

t_list	*ft_lstpop(t_list **head)
{
	t_list	*pop;

	if (!*head)
		return (NULL);
	pop = *head;
	*head = pop->next;
	pop->next = NULL;
	return (pop);
}

t_list	*ft_swap(t_list *lst)
{
	t_list	tmp;

	tmp.next = NULL;
	tmp.content = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp.content;
	return (lst);
}

t_list	*ft_rotate(t_list **head)
{
	t_list	*old_head;
	t_list	*new_head;

	old_head = *head;
	new_head = *head;
	while (new_head->next)
		new_head = new_head->next;
	*head = old_head->next;
	old_head->next = NULL;
	new_head->next = old_head;
	return (*head);
}

t_list	*ft_rev_rotate(t_list **head)
{
	t_list	*new_head;
	t_list	*new_end;

	new_head = *head;
	while (new_head->next)
	{
		new_end = new_head;
		new_head = new_head->next;
	}
	new_end->next = NULL;
	new_head->next = *head;
	*head = new_head;
	return (*head);
}

t_list	*ft_push(t_list **src, t_list **dest)
{
	t_list	*src_stack;

	src_stack = *src;
	if (src_stack->next)
	{
		*src = src_stack->next;
		ft_lstadd_front(dest, ft_lstpop(&src_stack));
	}
	else
	{	
		*src = NULL;
		ft_lstadd_front(dest, src_stack);
	}
	return (*src);
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

void	create_list(t_list **head, int i, int flag, char **argv)
{
	int		num;

	while (argv[i])
	{
		overflow_check(ft_atoi(argv[i]), argv[i], *head);
		num = ft_atoi(argv[i]);
		if (flag)
			ft_free(argv[i]);
		i++;
		ft_lstadd_back(head, ft_lstnew(&num, sizeof(int)));
	}
	if (flag)
		ft_free(argv);
	duplicate_check(*head);
}

void	emplement_operation(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strncmp("sa", line, ft_strlen(line)) == 0)
		ft_swap(*stack_a);
	if (ft_strncmp("sb", line, ft_strlen(line)) == 0)
		ft_swap(*stack_b);
	if (ft_strncmp("ra", line, ft_strlen(line)) == 0)
		ft_rotate(stack_a);
	if (ft_strncmp("rb", line, ft_strlen(line)) == 0)
		ft_rotate(stack_b);
	if (ft_strncmp("rra", line, ft_strlen(line)) == 0)
		ft_rev_rotate(stack_a);
	if (ft_strncmp("rrb", line, ft_strlen(line)) == 0)
		ft_rev_rotate(stack_b);
	if (ft_strncmp("pb", line, ft_strlen(line)) == 0)
		ft_push(stack_a, stack_b);
	if (ft_strncmp("pa", line, ft_strlen(line)) == 0)
		ft_push(stack_b, stack_a);
}

void	checker(t_list **head)
{
	t_list	*stack_b;
	char	*line;
	int		ret;

	stack_b = NULL;
	line = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (!ret)
			break ;
		emplement_operation(head, &stack_b, line);
		ft_free(line);
	}
	if (lst_sorted(*head))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free(line);
}

int	main(int argc, char **argv)
{
	int				i;
	t_list			*stack_a;
	int				flag;

	i = 1;
	flag = 0;
	stack_a = NULL;
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
		if (ft_lstsize(stack_a) > 1 && !lst_sorted(stack_a))
			checker(&stack_a);
	}
	ft_lstclear(&stack_a, ft_free);
	system("leaks checker");
	exit(EXIT_SUCCESS);
}
