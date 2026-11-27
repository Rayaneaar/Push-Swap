/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 15:17:20 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/27 15:28:08 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_handler(t_stack *stack)
{
	t_node	*old_node;

	if (stack->size <= 1)
		return (0);
	old_node = stack->head->next;
	stack->head->next = old_node->next;
	stack->head->prev = old_node->prev;
	stack->size--;
	add_front(stack, old_node);
	return (1);
}
int	swap(t_stack *stack_a, t_stack *stack_b, t_operation op)
{
	if (!stack_a || !stack_b)
		return (0);
	if (op == SA)
		return (swap_handler(stack_a));
	else if (op == SB)
		return (swap_handler(stack_b));
	else if (op == SS)
		return (swap_handler(stack_a) && swap_handler(stack_a));
	else
		return (0);
	return (1);
}
