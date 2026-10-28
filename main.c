#include "header_files/pushswap.h"
#include <stdio.h>

static void	print_stack(char *twasel_ma3e, t_stack *s)
{
	t_node	*cur;

	printf("%s: ", twasel_ma3e);
	cur = s->head;
	while (cur)
	{
		printf("%d ", cur->content);
		cur = cur->prev;
	}
	printf("\n");
}

//  int	main(void)
//  {
//  	t_stack	*a;
//  	t_stack	*b;

//  	a = init_stack();
//  	b = init_stack();
//  	add_new_node(a, 46);
//  	add_new_node(a, 21);
//  	add_new_node(a, 53);
//  	add_new_node(a, 11);
//  	add_new_node(a, 31);

// // 	print_stack("before ", a);

// // 	sa(a, 1);
// // 	print_stack("sa     ", a);
	

// // 	pb(b, a, 1);
// // 	print_stack("pb (a) ", a);
// // 	print_stack("pb (b) ", b);
	
	
// // 	pa(a, b, 1);
// // 	print_stack("pa (a) ", a);
// // 	print_stack("pa (b) ", b);

// // 	ra(a, 1);
//  //	print_stack("ra     ", a);
	
	
//  //	rra(a, 1);
//  //	print_stack("rra    ", a);

//  	int arr[] = {31,11,21,53,46}; // consider this the parsed array
//  	merge_sort(arr, 0, 4);
//  	binary_search(a, arr);
// //	complex(a, b, 0);
// 	selection_sort(a,b,0);
// // 	meduim_sort(a,b,0);
//  	print_stack("after selection sort: ", a);
//  	return (0);
//  }

int   main(void)
{
 	t_stack     *a;
 	t_stack     *b;

 	int     arr[10] = {7,2,5,0,8,3,1,9,6,4};
 	int		i;
 	a = init_stack();
 	b = init_stack();
 	i = 9;
 	while (i >= 0)
	add_new_node(a, arr[i--]);
 	print_stack("a before", a);
 	medium_sort(a, b, 0);
 	print_stack("a after ", a);
 	print_stack("b after ", b);
 	return (0);
}
