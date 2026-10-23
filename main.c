#include "header_files/pushswap.h"
#include <stdio.h>

static void	print_stack(char *twasel_ma3e, t_stack *s)
{
	t_node	*cur;

	printf("%s: ", twasel_ma3e);
	cur = s->tail;
	while (cur)
	{
		printf("%d ", cur->content);
		cur = cur->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack();
	b = init_stack();
	add_new_node(a, 44);
	add_new_node(a, 3);
	add_new_node(a, 20);
	add_new_node(a, 1);
/*
	print_stack("before ", a);

	sa(a, 1);
	print_stack("sa     ", a);
	

	pb(b, a, 1);
	print_stack("pb (a) ", a);
	print_stack("pb (b) ", b);
	
	
	pa(a, b, 1);
	print_stack("pa (a) ", a);
	print_stack("pa (b) ", b);


	ra(a, 1);
	print_stack("ra     ", a);
	
	
	rra(a, 1);
	print_stack("rra    ", a);
*/
	print_stack("a before ", a);
	int arr[] = {44, 3, 20, 1}; // consider this the parsed array
	merge_sort(arr, 0, 3);
	binary_search(a, arr);
	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	print_stack("\na after ", a);
	return (0);
}
