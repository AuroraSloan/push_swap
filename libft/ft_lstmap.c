#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*),
		size_t data_size)
{
	t_list	*new_element;
	t_list	*new_lst;

	if (!lst || !*f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content), data_size);
		if (!new_element)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_element);
		lst = lst->next;
	}
	return (new_lst);
}
