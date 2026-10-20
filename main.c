#include "header_files/pushswap.h"
#include <stdio.h>

int main()
{
	t_stack *stackA = init_stack();
	t_node *node1 = new_node(stackA, 1);
	t_node *node2 = new_node(stackA, 2);
	t_node *node3 = new_node(stackA, 3);
	t_node *node4 = new_node(stackA, 4);

	t_node	*curr = stackA->tail;
	printf("before: ");
	while (curr)
	{
		printf("%d ", curr->content);
		curr = curr->next;
	}
	printf("\n");
	revrot(&stackA);
	printf("after: ");
	curr = stackA->tail;
	while (curr)
	{
		printf("%d ", curr->content);
		curr = curr->next;
	}
}
