/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:27:48 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/27 15:26:43 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_handler(t_stack *from_s, t_stack *to_s)
{
	t_node	*new_head;
	t_node	*pushed_node;

	if (from_s->size == 0)
		return (0);
	new_head = from_s->head->next;
	pushed_node = from_s->head;
	add_front(to_s, pushed_node);
	from_s->head = new_head;
	from_s->size--;
	return (1);
}
int	push(t_stack *stack_a, t_stack *stack_b, t_operation op)
{
	if (!stack_a || !stack_b || !op)
		return (0);
	if (op == PA)
		return (push_handler(stack_b, stack_a));
	else if (op == PB)
		return (push_handler(stack_a, stack_b));
	else
		return (0);
	return (1);
}
