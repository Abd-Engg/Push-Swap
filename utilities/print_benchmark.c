#include "../header_files/ft_printf.h"
#include "../header_files/pushswap.h"

int	total_operations(t_stack *a, t_stack *b)
{
	int	ops;

	ops = a->op.s + b->op.s + a->op.ss + a->op.p + b->op.p;
	ops += a->op.rot + b->op.rot + a->op.rot_both + a->op.revrot;
	ops += b->op.revrot + a->op.revrot_both;
	return (ops);
}

char	*complexity(float dis, t_stack *a)
{
	if (dis < 0.2 || a->size <= 5)
		return ("O(n²)");
	if (dis < 0.5)
		return ("O(n√n)");
	return ("O(nlogn)");
}

void	print_benchmark(t_stack *a, t_stack *b, float dis, t_parsing _input)
{
	ft_printf(2, "[bench] disorder: %f%%\n", dis);
	if (_input.str == 1)
		ft_printf(2, "[bench] strategy: Simple / O(n²)\n");
	else if (_input.str == 2)
		ft_printf(2, "[bench] strategy: Medium / O(n√n) \n");
	else if (_input.str == 3)
		ft_printf(2, "[bench] strategy: Complex / O(nlogn)\n");
	else if (_input.str == 4)
	{
		ft_printf(2, "[bench] strategy: Adaptive / ");
		ft_printf(2, "%s\n", complexity(dis, a));
	}
	ft_printf(2, "[bench] total_ops: %d\n", total_operations(a, b));
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		a->op.s, b->op.s, a->op.ss, a->op.p, b->op.p);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		a->op.rot, b->op.rot, a->op.rot_both, a->op.revrot,
		b->op.revrot, a->op.revrot_both);
}
