#include "header_files/pushswap.h"
#include <stdio.h>

int main()
{
	t_stack *stackA = init_stack();
	t_node *node1 = new_node(stackA, 1);
	t_node *node2 = new_node(stackA, 2);
	t_node *node3 = new_node(stackA, 3);

	printf("before: %d %d\n", stackA->tail->content, stackA->head->content);
	swap(&stackA);
	printf("after: %d %d\n", stackA->tail->content, stackA->head->content);
}
