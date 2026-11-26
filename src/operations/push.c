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

// from_s the stack to take from
// to_s the stack to put to
//
// from_s should not be empty
// take the first top element form the from_s
int	push(t_stack *from_s, t_stack *to_s, t_operation op)
{
	t_node	*from_top;

	if (from_s->size == 0)
		return (0);
	from_top = from_s->head;
}
