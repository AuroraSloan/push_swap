#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

bool	lst_sorted(t_list *lst)
{
	int	ret;

	ret = true;
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
		{
			ret = false;
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
				ft_failed_exit("Error", NULL);
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
		ft_failed_exit("Error", NULL);
	}
	ft_free(revert);
}
