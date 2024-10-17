#include "inc/push_swap.h"

void init_stacks(t_stack **stack_a, t_stack **stack_b, long *values_a, long *values_b)
{
	// Free existing stacks if they are not NULL
	if (*stack_a)
	{
		t_stack *current = *stack_a;
		while (current)
		{
			t_stack *temp = current;
			current = current->next;
			free(temp);
		}
	}

	if (*stack_b)
	{
		t_stack *current = *stack_b;
		while (current)
		{
			t_stack *temp = current;
			current = current->next;
			free(temp);
		}
	}

//!	Initialize stack A
	*stack_a = malloc(sizeof(t_stack));
	(*stack_a)->nbr = values_a[0];
	(*stack_a)->next = malloc(sizeof(t_stack));
	(*stack_a)->next->nbr = values_a[1];
	(*stack_a)->next->next = malloc(sizeof(t_stack));
	(*stack_a)->next->next->nbr = values_a[2];
	(*stack_a)->next->next->next = NULL;

//!	Initialize stack B
	*stack_b = malloc(sizeof(t_stack));
	(*stack_b)->nbr = values_b[0];
	(*stack_b)->next = malloc(sizeof(t_stack));
	(*stack_b)->next->nbr = values_b[1];
	(*stack_b)->next->next = malloc(sizeof(t_stack));
	(*stack_b)->next->next->nbr = values_b[2];
	(*stack_b)->next->next->next = NULL;
}

void print_stack(t_stack *stack)
{
	t_stack *current = stack;
	while (current)
	{
		printf("%ld\n", current->nbr);
		current = current->next;
	}
}

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current_a = stack_a;
	t_stack *current_b = stack_b;

	while (current_a || current_b)
	{
		if (current_a && current_b)
		{
			printf("%ld --- %ld\n", current_a->nbr, current_b->nbr);
		} else if (current_a)
		{
			printf("%ld ---  \n", current_a->nbr);
		} else if (current_b)
		{
			printf("  --- %ld\n", current_b->nbr);
		}
		if (current_a)
			current_a = current_a->next;
		if (current_b)
			current_b = current_b->next;
	}
}

void free_stacks(t_stack *stack) {
	t_stack *current = stack;
	while (current) {
		t_stack *temp = current;
		current = current->next;
		free(temp);
	}
}

int main(int ac, char **av)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	long values_a[3] = {atol(av[1]), atol(av[2]), atol(av[3])};
	long values_b[3] = {10, 20, 30};
	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	sa
	printf("Before sa:\n");
	print_stack(stack_a);
	sa(&stack_a);
	printf("After sa:\n");
	print_stack(stack_a);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	sb
	printf("Before sb:\n");
	print_stack(stack_b);
	sb(&stack_b);
	printf("After sb:\n");
	print_stack(stack_b);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	ss
	printf("Before ss:\n");
	print_stacks(stack_a, stack_b);
	ss(&stack_a, &stack_b);
	printf("After ss:\n");
	print_stacks(stack_a, stack_b);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//! pa
	printf("Before pa:\n");
	print_stacks(stack_a, stack_b);
	pa(&stack_b, &stack_a);
	printf("After pa:\n");
	print_stacks(stack_a, stack_b);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	pb
	printf("Before pb:\n");
	print_stacks(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	printf("After pb:\n");
	print_stacks(stack_a, stack_b);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	ra
	printf("Before ra:\n");
	print_stack(stack_a);
	ra(&stack_a);
	printf("After ra:\n");
	print_stack(stack_a);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	rb
	printf("Before rb:\n");
	print_stack(stack_b);
	rb(&stack_b);
	printf("After rb:\n");
	print_stack(stack_b);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	rr
	printf("Before rr:\n");
	print_stacks(stack_a, stack_b);
	rr(&stack_a, &stack_b);
	printf("After rr:\n");
	print_stacks(stack_a, stack_b);
	printf("\n");
	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	rra
	printf("Before rra:\n");
	print_stack(stack_a);
	rra(&stack_a);
	printf("After rra:\n");
	print_stack(stack_a);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	rrb
	printf("Before rrb:\n");
	print_stack(stack_b);
	rrb(&stack_b);
	printf("After rrb:\n");
	print_stack(stack_b);
	printf("\n");

	init_stacks(&stack_a, &stack_b, values_a, values_b);

//!	rrr
	printf("Before rrr:\n");
	print_stacks(stack_a, stack_b);
	rrr(&stack_a, &stack_b);
	printf("After rrr:\n");
	print_stacks(stack_a, stack_b);
	printf("\n");

//!	Free the stacks before exiting
	free_stacks(stack_a);
	free_stacks(stack_b);
}
