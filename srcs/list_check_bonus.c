/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:44:54 by jthompso          #+#    #+#             */
/*   Updated: 2021/07/02 15:47:57 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

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
