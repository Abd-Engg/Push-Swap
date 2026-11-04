#include "header_files/pushswap.h"
#include "header_files/ft_printf.h"
#include <stdio.h>

void free_stack(t_stack *s)
{
	t_node *cur = s->head;
	while (cur)
	{
		t_node *tmp = cur;
		cur = cur->prev;
		free(tmp);
	}
	free(s);
}

void	selector(parsing _input, t_stack *a, t_stack *b)
{
	float	dis;
	int		flag;

	flag = 0;
	dis = disorder(a, a->size);
	if (_input.str == adaptive)
	{
		_input.str = _disorder(a);
		flag = 1;
	}
	if (_input.str == complex)
		complex_sort(a, b, _input.is_bench);
	else if (_input.str == medium)
		medium_sort(a, b, _input.is_bench);
	else if (_input.str == simple)
		selection_sort(a, b, _input.is_bench);
	if (flag)
		_input.str = adaptive;
	if (_input.is_bench)
		print_benchmark(a, b, dis, _input);
}

void PushSwap(parsing _input)
{
	t_stack *a;
	t_stack *b;
	int		i;

	i = _input.size - 1;
	a = init_stack();
	b = init_stack();
	if (_input.error)
	{
		ft_printf(2, "ERROR\n");
		return ;
	}
	while (i >= 0)
		add_new_node(a, _input.data[i--]);
	merge_sort(_input.data, 0, _input.size - 1);	
	binary_search(a, _input.data);
	selector(_input, a, b);
	free_stack(a);
	free_stack(b);
	free(_input.data);
}

int main(int argc,char **argv)
{
	parsing _input;
	_input = parsing_input(argv + 1, argc - 1);
	PushSwap(_input);
	return (0);
}
