/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 13:15:05 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/26 22:03:34 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_operation;
// Parser functions
int					ft_isspace(int c);
int					validate_number(long n);
int					is_dup(t_stack *stack, int c);
int					get_number(char *str, int *j, int *success);
int					parser(t_stack *stack, char *argument);

// Node functions
void				ft_node_clear(t_stack *stack);
void				add_back(t_stack *stack, t_node *new_node);
void				add_front(t_stack *stack, t_node *new_node);
t_node				*create_new_node(int value);

// stack functions
void				print_stack(t_stack stack);
void				init_stack(t_stack *stack);

// utils functions
int					handle_error(int *error);

// operetions functions

int					push(t_stack *from_s, t_stack *to_s);
#endif
