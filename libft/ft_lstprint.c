#include "libft.h"

void	ft_lstprint(t_list *lst, void (*fptr)(void *))
{
	while (lst != NULL)
	{
		(*fptr)(lst->content);
		lst = lst->next;
	}
}
