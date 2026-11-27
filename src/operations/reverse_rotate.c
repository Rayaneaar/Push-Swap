/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 16:27:42 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/27 16:49:46 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_reverse_rotate(t_stack *stack)
{
	t_node	*old_node;

	if (!stack || stack->size <= 1)
		return (0);
	old_node = stack->tail;
	stack->tail = old_node->prev;
	stack->tail->next = NULL;
	stack->size--;
	add_front(stack, old_node);
	return (1);
}

int	reverse_rotate(t_stack *stack_a, t_stack *stack_b, t_operation op)
{
	if (!stack_a || !stack_b)
		return (0);
	if (op == RRA)
		return (handle_reverse_rotate(stack_a));
	else if (op == RRB)
		return (handle_reverse_rotate(stack_b));
	else if (op == RRR)
		return (handle_reverse_rotate(stack_b)
			&& handle_reverse_rotate(stack_a));
	else
		return (0);
	return (1);
}
