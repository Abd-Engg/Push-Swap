#include "../header_files/pushswap.h"
#include <stdio.h>

int	chunk_sizee(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

// void stage_A(t_stack *sa,t_stack *sb,int bench)
// {
//     int chunk_size = chunk_sizee(sa->size);
//     int num_chunks = (sa->size + chunk_size - 1) / chunk_size;
//     int counter;
//     int start;
//     int end;
//     int i = 0;
//     while (num_chunks--)
//     {
//         counter = 0;
//         start = i++ * chunk_size;
//         end = start + chunk_size - 1;
//         while (counter < chunk_size && sa->size)
//         {
//             if (sa->head->content <= end && sa->head->content >= start)
//             {
//                 pb(sb,sa,bench);
//                 counter++;
//             }
//             else
//                 ra(sa,bench);
//         }
//     }
// }

void	stage_a(t_stack *sa, t_stack *sb, int bench)
{
	int	chunk;
	int	start;
	int	counter;

	chunk = chunk_sizee(sa->size);
	start = 0;
	while (sa->size)
	{
		counter = 0;
		while (counter < chunk && sa->size)
		{
			if (sa->head->content >= start && sa->head->content < start + chunk)
			{
				pb(sb, sa, bench);
				counter++;
			}
			else
				ra(sa, bench);
		}
		start += chunk;
	}
}

void	rotatee(t_stack *s, int index, int bench)
{
	int	tmp;
	if (index <= 0)
		return ;
	if (index <= s->size / 2)
	{
		while (index)
        {
			rb(s, bench);
            index--;
        }
	}
	else
	{
		tmp = s->size - index;
		while (tmp--)
        	rrb(s, bench);
	}
}

void medium_sort(t_stack *sa, t_stack *sb, int bench)
{
    stage_a(sa,sb,bench);
    int target = 0;
    while (sb->size)
    {
        int index = pos(sb,target);
        rotatee(sb,index,bench);
        pa(sa,sb,bench);
        target++;
    }
}
