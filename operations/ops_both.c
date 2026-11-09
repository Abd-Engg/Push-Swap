#include "../header_files/ft_printf.h"
#include "../header_files/pushswap.h"

void	ss(t_stack *sa, t_stack *sb)
{
	ft_printf(1, "ss\n");
	swap(sa);
	swap(sb);
	sa->op.ss++;
}

void	rr(t_stack *sa, t_stack *sb)
{
	ft_printf(1, "rr\n");
	rot(sa);
	rot(sb);
	sa->op.rot_both++;
}

void	rrr(t_stack *sa, t_stack *sb)
{
	ft_printf(1, "rrr\n");
	revrot(sa);
	revrot(sb);
	sa->op.revrot_both++;
}
