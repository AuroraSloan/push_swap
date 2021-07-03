#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_int_data
{
	int	data;
	int	loc;
}				t_int_data;

typedef struct s_info
{
	t_list	*stack_len;
	int		part_len;	
	int		sort_by;
}				t_info;

int		main(int argc, char **argv);
void	ft_swap(t_list *lst, char *operation);
void	ft_rotate(t_list **head, char *operation);
void	ft_rev_rotate(t_list **head, char *operation);
void	ft_push(t_list **src, t_list **dest, char *operation);
t_list	*ft_lstpop(t_list **head);
void	swap_both(t_list **stack_a, t_list **stack_b, char *operation);
void	rotate_both(t_list **stack_a, t_list **stack_b, char *operation);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b, char *operation);
int		lst_sorted(t_list *lst);
int		lst_rev_sorted(t_list *lst);
void	duplicate_check(t_list *lst);
void	overflow_check(int num, char *str, t_list *lst);
t_list	*push_swap_three(t_list **head);
void	init_list_min(t_list *stack, t_int_data *int_data);
void	init_list_max(t_list *stack, t_int_data *int_data);
void	push_min_max(t_list **src, t_list **dest, t_int_data int_data);
void	push_swap_small(t_list **head, t_list **stack_b);
void	make_sorted_list(t_list *stack, t_list **sorted, int len);
void	push_swap_large(t_list **stack_a, t_list **stack_b, t_info *info);
void	sort_to_a(t_list **stack_a, t_list **stack_b);
int		find_pivot(t_list *sorted, int center);
int		pivot_to_a(t_list **stack_a, t_list **stack_b, t_list *sorted,
			int pivot);
int		pivot_to_b(t_list **stack_a, t_list **stack_b, t_list *sorted);
void	partition_stack(t_list **stack_a, t_list **stack_b, t_info *info);
void	failed_exit(char *exit_mssg);

#endif
