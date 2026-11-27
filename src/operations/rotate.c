/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 15:14:50 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/27 15:31:06 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_rotate(t_stack *stack)
{
	int	temp;

	if (!stack || stack->size <= 1)
		return (0);
	temp = stack->head->value;
	stack->head->value = stack->tail->value;
	stack->tail->value = temp;
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
		return (handle_rotate(stack_b) && handle_rotate(stack_a));
	else
		return (0);
	return (1);
}
