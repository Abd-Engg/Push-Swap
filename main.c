#include "header_files/pushswap.h"
#include "header_files/ft_printf.h"
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

void	selector(parsing _input, t_stack *a, t_stack *b)
{
	float	dis;
	int		flag;

	flag = 0;
	dis = disorder(a, a->size);
	print_stack("a stack before ", a);
	if (_input.str == adaptive)
	{
		_input.str = _disorder(a);
		flag = 1;
	}
	if (_input.str == complex)
	{
		complex_sort(a, b, _input.is_bench);
		print_stack("a stack complex ", a);
	}
	else if (_input.str == medium)
	{
		medium_sort(a, b, _input.is_bench);
		print_stack("a stack medium ", a);
	}
	else if (_input.str == simple)
	{
		selection_sort(a, b, _input.is_bench);
		print_stack("a stack simple ", a);
	}
	print_stack("a stack after ", a);
	if (flag)
		_input.str = adaptive;
	if (_input.is_bench)
		print_benchmark(a, b, dis, _input);
}

int main(int argc,char **argv)
{
	parsing _input;
	t_stack *a;
	t_stack *b;
	int		i;

	i = 0;
	_input = parsing_input(argv + 1, argc - 1);
	a = init_stack();
	b = init_stack();
	if (_input.error)
	{
		ft_printf(2, "ERROR\n");
		return (0);
	}
	while (i < _input.size)
		add_new_node(a, _input.data[i++]);
	merge_sort(_input.data, 0, _input.size - 1);	
	binary_search(a, _input.data);
	selector(_input, a, b);
}

// int	main(void)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = init_stack();
// 	b = init_stack();
// 	add_new_node(a, 1);
// 	add_new_node(a, 2);
// 	add_new_node(a, 3);
// 	add_new_node(a, 4);

// 	int arr[] = {1, 2, 3, 4}; // consider this the parsed array
// 	merge_sort(arr, 0, 3);
// 	binary_search(a, arr);

// 	complex(a, b, 1);
// 	print_stack("after complex sort: ", a);
// 	ft_printf("%f%%", disorder(a, 4));
// 	return (0);
// }
