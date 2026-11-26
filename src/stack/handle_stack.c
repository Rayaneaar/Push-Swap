/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:54:19 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/26 21:00:58 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
void	print_stack(t_stack stack)
{
	t_node	*cur;

	cur = stack.head;
	while (cur)
	{
		ft_printf("%d\n", cur->value);
		cur = cur->next;
	}
}
