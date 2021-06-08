/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:11:26 by jthompso          #+#    #+#             */
/*   Updated: 2021/06/08 21:35:38 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	failed_exit(char *exit_mssg)
{
	ft_putendl_fd(exit_mssg, 2);
	exit(EXIT_FAILURE);
}

t_list	*ft_swap(t_list *lst, char *operation)
{
	t_list	tmp;

	tmp.next = NULL;
	tmp.content = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp.content;
	ft_putendl(operation);
	return (lst);
}

t_list	*ft_rotate(t_list **head, char *operation)
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
	ft_putendl(operation);
	return (*head);
}

t_list	*ft_rev_rotate(t_list **head, char *operation)
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
	ft_putendl(operation);
	return (*head);
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

int	main(int argc, char **argv)
{
	
}
