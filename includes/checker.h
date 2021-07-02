/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:05:39 by jthompso          #+#    #+#             */
/*   Updated: 2021/07/02 16:03:28 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

int	main(int argc, char **argv);
void	ft_swap(t_list *lst, char *operation);
void	ft_rotate(t_list **head, char *operation);
void	ft_rev_rotate(t_list **head, char *operation);
void	ft_push(t_list **src, t_list **dest, char *operation);
t_list	*ft_lstpop(t_list **head);
void	swap_both(t_list **stack_a, t_list **stack_b, char *operation);
void	rotate_both(t_list **stack_a, t_list  **stack_b, char *operation);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b, char *operation);
int	lst_sorted(t_list *lst);
void	duplicate_check(t_list *lst);
void	overflow_check(int num, char *str, t_list *lst);
void	create_list(t_list **head, int i, int flag, char **argv);
void	failed_exit(char *exit_mssg);

# endif
