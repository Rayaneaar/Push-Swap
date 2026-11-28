/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 15:14:50 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/27 16:49:20 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_rotate(t_stack *stack)
{
	t_node	*old_node;

	if (!stack || stack->size <= 1)
		return (0);
	old_node = stack->head;
	stack->head = old_node->next;
	stack->head->prev = NULL;
	stack->size--;
	add_back(stack, old_node);
	return (1);
}

int	rotate(t_stack *stack_a, t_stack *stack_b, t_operation op)
{
	if (!stack_a || !stack_b)
		return (0);
	if (op == RA)
		return (handle_rotate(stack_a));
	else if (op == RB)
		return (handle_rotate(stack_b));
	else if (op == RR)
		return (handle_rotate(stack_b) | handle_rotate(stack_a));
	else
		return (0);
}
