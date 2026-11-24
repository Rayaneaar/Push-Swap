#include "push_swap.h"
#include <threads.h>

void	init_stack(t_stack *stack)
{
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

int	main(int ac, char **av)
{
	int		i;
	t_stack	stack_a;
	int		number;
	t_node	*node;

	if (ac < 2)
		return (0);
	i = 1;
	init_stack(&stack_a);
	while (i < ac)
	{
		number = ft_atoi(av[i]);
		node = create_new_node(number);
		add_back(&stack_a, node);
		i++;
	}
	print_stack(stack_a);
}
