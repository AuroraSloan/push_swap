#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

void	ft_swap(t_list *lst, char *operation)
{
	t_list	tmp;

	if (!lst || ft_lstsize(lst) < 2)
		return ;
	tmp.next = NULL;
	tmp.content = lst->next->content;
	tmp.location = lst->next->location;
	lst->next->content = lst->content;
	lst->next->location = lst->location;
	lst->content = tmp.content;
	lst->location = tmp.location;
	if (operation)
		ft_putendl(operation);
}

void	ft_rotate(t_list **head, char *operation)
{
	t_list	*old_head;
	t_list	*new_head;

	if (!*head || ft_lstsize(*head) < 2)
		return ;
	old_head = *head;
	new_head = *head;
	while (new_head->next)
		new_head = new_head->next;
	*head = old_head->next;
	old_head->next = NULL;
	new_head->next = old_head;
	if (operation)
		ft_putendl(operation);
}

void	ft_rev_rotate(t_list **head, char *operation)
{	
	t_list	*new_head;
	t_list	*new_end;

	if (!*head || ft_lstsize(*head) < 2)
		return ;
	new_head = *head;
	while (new_head->next)
	{
		new_end = new_head;
		new_head = new_head->next;
	}
	new_end->next = NULL;
	new_head->next = *head;
	*head = new_head;
	if (operation)
		ft_putendl(operation);
}

void	ft_push(t_list **src, t_list **dest, char *operation)
{
	t_list	*src_stack;	

	if (!*src)
		return ;
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
	if (operation)
		ft_putendl(operation);
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
