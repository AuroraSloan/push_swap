/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:32:31 by jthompso          #+#    #+#             */
/*   Updated: 2021/07/02 16:29:01 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

static void	emplement_operation(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strncmp("rr", line, ft_strlen(line)) == 0)
		rotate_both(stack_a, stack_b, NULL);
	else if (ft_strncmp("ss", line, ft_strlen(line)) == 0)
		swap_both(stack_a, stack_b, NULL);
	else if (ft_strncmp("sa", line, ft_strlen(line)) == 0)
		ft_swap(*stack_a, NULL);
	else if (ft_strncmp("sb", line, ft_strlen(line)) == 0)
		ft_swap(*stack_b, NULL);
	else if (ft_strncmp("ra", line, ft_strlen(line)) == 0)
		ft_rotate(stack_a, NULL);
	else if (ft_strncmp("rb", line, ft_strlen(line)) == 0)
		ft_rotate(stack_b, NULL);
	else if (ft_strncmp("pb", line, ft_strlen(line)) == 0)
		ft_push(stack_a, stack_b, NULL);
	else if (ft_strncmp("pa", line, ft_strlen(line)) == 0)
		ft_push(stack_b, stack_a, NULL);
	else if (ft_strncmp("rrr", line, ft_strlen(line)) == 0)
		rev_rotate_both(stack_a, stack_b, NULL);
	else if (ft_strncmp("rra", line, ft_strlen(line)) == 0)
		ft_rev_rotate(stack_a, NULL);
	else if (ft_strncmp("rrb", line, ft_strlen(line)) == 0)
		ft_rev_rotate(stack_b, NULL);
	else
		failed_exit("Error");
}

static void	checker(t_list **head)
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
	/*	create_list(&stack_a, i, flag, argv);
		if (lst_sorted(stack_a))
			ft_putendl("OK");
		if (ft_lstsize(stack_a) > 1 && !lst_sorted(stack_a))*/
		if (ft_lstsize(stack_a) >= 1)
			checker(&stack_a);
		ft_putendl("ok");
	}
	ft_lstclear(&stack_a, ft_free);
	exit(EXIT_SUCCESS);
}
