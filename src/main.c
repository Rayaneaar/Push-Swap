/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 15:02:47 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/27 16:50:42 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	i = 1;
	while (i < ac)
	{
		if (parser(&stack_a, av[i]) == -1 || stack_a.size == 0)
		{
			ft_printf("Error\n");
			ft_node_clear(&stack_a);
			return (1);
		}
		i++;
	}
	push(&stack_a, &stack_b, PB);
	push(&stack_a, &stack_b, PB);
	push(&stack_a, &stack_b, PB);
	ft_printf("\n========== BEFORE ROTATE (RA) ==========\n");
	ft_printf("\n--- STACK A ---\n");
	print_stack(stack_a);
	ft_printf("\n--- STACK B ---\n");
	print_stack(stack_b);
	reverse_rotate(&stack_a, &stack_b, RRR);
	ft_printf("\n========== AFTER ROTATE (RA) ==========\n");
	ft_printf("\n--- STACK A ---\n");
	print_stack(stack_a);
	ft_printf("\n--- STACK B ---\n");
	print_stack(stack_b);
	ft_node_clear(&stack_a);
	ft_node_clear(&stack_b);
	return (0);
}
