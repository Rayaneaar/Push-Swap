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

int	rotate(t_stack *stack)
{
	int	temp;

	if (!stack || stack->size <= 1)
		return (0);
	temp = stack->head->value;
	stack->head->value = stack->tail->value;
	stack->tail->value = temp;
	return (1);
}
