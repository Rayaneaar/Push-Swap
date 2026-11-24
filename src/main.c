#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
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

int	ft_isspace(int c)
{
	if ((c >= 9 || c <= 13 || c == 32))
		return (1);
	return (0);
}

int	is_dup(t_stack *stack, int c)
{
	t_node	*curr;

	if (stack->size == 0)
		return (1);
	curr = stack->head;
	while (curr)
	{
		if (curr->value == c)
			return (-1);
		curr = curr->next;
	}
	return (1);
}
int	argv_parser(t_stack *stack, char *str)
{
	int		j;
	int		sign;
	long	result;
	int		number;
	t_node	*new_node;

	j = 0;
	sign = 1;
	result = 0;
	while (str[j])
	{
		while (ft_isspace(str[j]))
			j++;
		ft_printf("%s", str);
		if (str[j] == '-' || str[j] == '+')
		{
			if (str[j] == '-')
				sign = -1;
			j++;
		}
		if (!ft_isdigit(str[j]))
			return (-1);
		while (str[j] && ft_isdigit(str[j]))
		{
			if (result > (LONG_MAX - (str[j] - '0')) / 10)
				return (-1);
			result = result * 10 + (str[j] - '0');
			j++;
		}
		if (str[j] && !ft_isspace(str[j]))
			return (-1);
		number = result * sign;
		if (is_dup(stack, number) == -1)
			return (-1);
		new_node = create_new_node(number);
		add_back(stack, new_node);
	}
	return (-1);
}

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
		argv_parser(&stack_a, av[i]);
		i++;
	}
	print_stack(stack_a);
	ft_node_clear(&stack_a);
}
