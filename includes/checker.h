#ifndef CHECKER_H
# define CHECKER_H

#include <stdbool.h>

int		main(int argc, char **argv);
void	ft_swap(t_list *lst, char *operation);
void	ft_rotate(t_list **head, char *operation);
void	ft_rev_rotate(t_list **head, char *operation);
void	ft_push(t_list **src, t_list **dest, char *operation);
t_list	*ft_lstpop(t_list **head);
void	swap_both(t_list **stack_a, t_list **stack_b, char *operation);
void	rotate_both(t_list **stack_a, t_list **stack_b, char *operation);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b, char *operation);
bool	lst_sorted(t_list *lst);
void	duplicate_check(t_list *lst);
void	overflow_check(int num, char *str, t_list *lst);
void	create_list(t_list **head, int i, int flag, char **argv);
void	free_and_exit(t_list **stack_a, t_list **stack_b);

#endif
