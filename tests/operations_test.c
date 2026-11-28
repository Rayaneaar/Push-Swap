
#include "push_swap.h"

static int	g_passed;
static int	g_failed;

static int	load_stack(t_stack *stack, const int *values, int size)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < size)
	{
		node = create_new_node(values[i]);
		if (!node)
			return (0);
		add_back(stack, node);
		i++;
	}
	return (1);
}

static int	check_stack(t_stack *stack, const int *expected, int size)
{
	t_node	*current;
	t_node	*previous;
	int		i;

	if (stack->size != size)
		return (0);
	if (size == 0)
		return (stack->head == NULL && stack->tail == NULL);
	if (!stack->head || !stack->tail)
		return (0);
	if (stack->head->prev != NULL || stack->tail->next != NULL)
		return (0);
	current = stack->head;
	previous = NULL;
	i = 0;
	while (current && i < size)
	{
		if (current->value != expected[i])
			return (0);
		if (current->prev != previous)
			return (0);
		previous = current;
		current = current->next;
		i++;
	}
	if (current != NULL || i != size)
		return (0);
	if (previous != stack->tail)
		return (0);
	return (1);
}

static void	execute_operation(t_stack *a, t_stack *b, t_operation op)
{
	if (op == SA || op == SB || op == SS)
		swap(a, b, op);
	else if (op == PA || op == PB)
		push(a, b, op);
	else if (op == RA || op == RB || op == RR)
		rotate(a, b, op);
	else if (op == RRA || op == RRB || op == RRR)
		reverse_rotate(a, b, op);
}

static void	run_test(char *name, t_operation op, const int *a_values,
		int a_size, const int *b_values, int b_size, const int *expected_a,
		int expected_a_size, const int *expected_b, int expected_b_size)
{
	t_stack	a;
	t_stack	b;
	int		success;

	init_stack(&a);
	init_stack(&b);
	if (!load_stack(&a, a_values, a_size) || !load_stack(&b, b_values, b_size))
	{
		ft_node_clear(&a);
		ft_node_clear(&b);
		ft_printf("FAIL: %s (allocation failed)\n", name);
		g_failed++;
		return ;
	}
	execute_operation(&a, &b, op);
	success = check_stack(&a, expected_a, expected_a_size) && check_stack(&b,
			expected_b, expected_b_size);
	if (success)
	{
		ft_printf("PASS: %s\n", name);
		g_passed++;
	}
	else
	{
		ft_printf("FAIL: %s\n", name);
		ft_printf("Stack A after operation:\n");
		print_stack(a);
		ft_printf("Stack B after operation:\n");
		print_stack(b);
		g_failed++;
	}
	ft_node_clear(&a);
	ft_node_clear(&b);
}

int	main(void)
{
	int	a123[] = {1, 2, 3};
	int	b456[] = {4, 5, 6};
	int	a12[] = {1, 2};
	int	a21[] = {2, 1};
	int	b9[] = {9};
	int	a1[] = {1};
	int	a231[] = {2, 3, 1};
	int	a312[] = {3, 1, 2};
	int	a213[] = {2, 1, 3};
	int	a23[] = {2, 3};
	int	b19[] = {1, 9};
	int	a19[] = {1, 9};
	int	b23[] = {2, 3};
	int	b123[] = {1, 2, 3};
	int	b564[] = {5, 6, 4};
	int	b645[] = {6, 4, 5};
	int	b546[] = {5, 4, 6};

	ft_printf("\n========== SWAP TESTS ==========\n");
	run_test("sa: swap first two in A", SA, a123, 3, NULL, 0, a213, 3, NULL, 0);
	run_test("sb: swap first two in B", SB, NULL, 0, b456, 3, NULL, 0, b546, 3);
	run_test("ss: swap both stacks", SS, a123, 3, b456, 3, a213, 3, b546, 3);
	run_test("sa: empty stack", SA, NULL, 0, NULL, 0, NULL, 0, NULL, 0);
	run_test("sb: one node", SB, NULL, 0, b9, 1, NULL, 0, b9, 1);
	run_test("ss: one node in each stack", SS, a1, 1, b9, 1, a1, 1, b9, 1);
	ft_printf("\n========== PUSH TESTS ==========\n");
	run_test("pb: move A head to B", PB, a123, 3, b9, 1, a23, 2, b19, 2);
	run_test("pa: move B head to A", PA, b9, 1, b123, 3, a19, 2, b23, 2);
	run_test("pb: move last node from A", PB, a1, 1, NULL, 0, NULL, 0, a1, 1);
	run_test("pa: move last node from B", PA, NULL, 0, a1, 1, a1, 1, NULL, 0);
	run_test("pb: source A is empty", PB, NULL, 0, b9, 1, NULL, 0, b9, 1);
	run_test("pa: source B is empty", PA, a1, 1, NULL, 0, a1, 1, NULL, 0);
	ft_printf("\n========== ROTATE TESTS ==========\n");
	run_test("ra: rotate A", RA, a123, 3, NULL, 0, a231, 3, NULL, 0);
	run_test("rb: rotate B", RB, NULL, 0, a123, 3, NULL, 0, a231, 3);
	run_test("rr: rotate both stacks", RR, a123, 3, b456, 3, a231, 3, b564, 3);
	run_test("ra: empty stack", RA, NULL, 0, NULL, 0, NULL, 0, NULL, 0);
	run_test("ra: one node", RA, a1, 1, NULL, 0, a1, 1, NULL, 0);
	run_test("rr: A empty, rotate B", RR, NULL, 0, a123, 3, NULL, 0, a231, 3);
	ft_printf("\n========== REVERSE ROTATE TESTS ==========\n");
	run_test("rra: reverse rotate A", RRA, a123, 3, NULL, 0, a312, 3, NULL, 0);
	run_test("rrb: reverse rotate B", RRB, NULL, 0, a123, 3, NULL, 0, a312, 3);
	run_test("rrr: reverse rotate both", RRR, a123, 3, b456, 3, a312, 3, b645,
		3);
	run_test("rra: empty stack", RRA, NULL, 0, NULL, 0, NULL, 0, NULL, 0);
	run_test("rra: one node", RRA, a1, 1, NULL, 0, a1, 1, NULL, 0);
	run_test("rrr: A empty, reverse rotate B", RRR, NULL, 0, a123, 3, NULL, 0,
		a312, 3);
	ft_printf("\n========== TWO-NODE TESTS ==========\n");
	run_test("ra: two nodes", RA, a12, 2, NULL, 0, a21, 2, NULL, 0);
	run_test("rra: two nodes", RRA, a12, 2, NULL, 0, a21, 2, NULL, 0);
	run_test("sa: two nodes", SA, a12, 2, NULL, 0, a21, 2, NULL, 0);
	ft_printf("\n========== RESULTS ==========\n");
	ft_printf("Passed: %d\n", g_passed);
	ft_printf("Failed: %d\n", g_failed);
	ft_printf("Total:  %d\n", g_passed + g_failed);
	if (g_failed == 0)
		ft_printf("ALL TESTS PASSED\n");
	else
		ft_printf("SOME TESTS FAILED\n");
	return (g_failed != 0);
}
