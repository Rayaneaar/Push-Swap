/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:27:48 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/26 20:40:37 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *stack_a, t_stack *stack_b, t_operation op)
{
	t_node	*new_head;
	t_node	*pushed_node;

	if (op == PA)
	{
		if (stack_b->size == 0)
			return (0);
		new_head = stack_b->head->next;
		pushed_node = stack_b->head;
		add_front(stack_a, pushed_node);
		stack_b->head = new_head;
		stack_b->size--;
	}
	else if (op == PB)
	{
		if (stack_a->size == 0)
			return (0);
		new_head = stack_a->head->next;
		pushed_node = stack_a->head;
		add_front(stack_b, pushed_node);
		stack_a->head = new_head;
		stack_a->size--;
	}
	return (0);
}
