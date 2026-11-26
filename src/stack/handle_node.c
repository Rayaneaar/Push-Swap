/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:52:05 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/26 21:01:00 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_clear(t_stack *stack)
{
	t_node	*next_node;
	t_node	*current;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	add_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if (stack->tail)
		stack->tail->next = new_node;
	else
		stack->head = new_node;
	stack->tail = new_node;
	stack->size++;
}

t_node	*create_new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
