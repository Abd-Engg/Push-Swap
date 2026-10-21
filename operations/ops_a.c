#include "../header_files/ft_printf.h"
#include "../header_files/pushswap.h"

void	sa(t_stack *sa, int bench)
{
	if (!bench)
		ft_printf("sa\n");
	swap(sa);
	sa->op.s++;
}

void	pa(t_stack *sa, t_stack *sb, int bench)
{
	if (!bench)
		ft_printf("pa\n");
	push(sa, sb);
	sa->op.p += 1;
}

void	ra(t_stack *sa, int bench)
{
	if (!bench)
		ft_printf("ra\n");
	rot(sa);
	sa->op.rot++;
}

void	rra(t_stack *sa, int bench)
{
	if (!bench)
		ft_printf("rra\n");
	revrot(sa);
	sa->op.revrot++;
}
