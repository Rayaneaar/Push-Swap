#include "libft.h"
#include "push_swap.h"

int	ft_isspace(int c)
{
	if (((c >= 9 && c <= 13) || c == 32))
		return (1);
	return (0);
}

int	parser(t_stack *stack, char *argument)
{
	int		j;
	int		success;
	int		number;
	t_node	*new_node;

	j = 0;
	success = 1;
	number = 0;
	if (!argument[j])
		return (-1);
	while (argument[j])
	{
		while (ft_isspace(argument[j]))
			j++;
		if (!argument[j])
			break ;
		number = get_number(argument, &j, &success);
		if (success == -1 || is_dup(stack, number) == -1)
			return (-1);
		new_node = create_new_node(number);
		add_back(stack, new_node);
	}
	return (1);
}
