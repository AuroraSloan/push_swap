/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:50:55 by jthompso          #+#    #+#             */
/*   Updated: 2021/06/26 02:58:45 by jthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_int_data
{
	int	data;
	int	loc;
}				t_int_data;

typedef struct	s_ps_list
{
	void				*content;
	int					location;
	struct s_ps_list	*next;
}				t_ps_list;

typedef struct	s_info
{
	int		stack_len;
	int		part_len;
}				t_info;

# endif
