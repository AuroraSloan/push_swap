/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:51:13 by jthompso          #+#    #+#             */
/*   Updated: 2021/07/02 15:51:47 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	create_list(t_list **head, int i, int flag, char **argv)
{
	int		num;
	t_list	*tmp;

	while (argv[i])
	{
		overflow_check(ft_atoi(argv[i]), argv[i], *head);
		num = ft_atoi(argv[i]);
		if (flag)
			ft_free(argv[i]);
		i++;
		ft_lstadd_back(head, ft_lstnew(&num, sizeof(int)));
		tmp = *head;
		tmp->location = 0;
	}
	if (flag)
		ft_free(argv);
	duplicate_check(*head);
}
