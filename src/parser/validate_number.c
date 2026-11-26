/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:02:42 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/26 22:02:59 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(t_stack *stack, int c)
{
	t_node	*curr;

	curr = stack->head;
	while (curr)
	{
		if (curr->value == c)
			return (-1);
		curr = curr->next;
	}
	return (1);
}

int	validate_number(long n)
{
	if (n < INT_MIN || n > INT_MAX)
		return (-1);
	return (0);
}
