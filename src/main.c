#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	t_stack	stack_a;

	if (ac < 2)
		return (0);
	i = 1;
	init_stack(&stack_a);
	while (i < ac)
	{
		if (parser(&stack_a, av[i]) == -1 || stack_a.size == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	print_stack(stack_a);
	ft_node_clear(&stack_a);
}
