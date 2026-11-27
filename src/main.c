#include "ft_printf.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	i = 1;
	init_stack(&stack_a);
	init_stack(&stack_b);
	while (i < ac)
	{
		if (parser(&stack_a, av[i]) == -1 || stack_a.size == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	ft_printf("\n========== BEFORE PUSH ==========\n");
	ft_printf("\n--- STACK A ---\n");
	print_stack(stack_a);
	ft_printf("\n--- STACK B ---\n");
	print_stack(stack_b);
	push(&stack_a, &stack_b);
	ft_printf("\n========== AFTER PUSH ==========\n");
	ft_printf("\n--- STACK A ---\n");
	print_stack(stack_a);
	ft_printf("\n--- STACK B ---\n");
	print_stack(stack_b);
	ft_node_clear(&stack_a);
	ft_node_clear(&stack_b);
}
