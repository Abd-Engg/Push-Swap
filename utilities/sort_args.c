#include <stdlib.h>
#include "../header_files/pushswap.h"

void	binary_search(t_stack *s, int *arr)
{
	t_node	*node;
	int		l;
	int		r;
	int		mid;

	node = s->tail;
	while (node)
	{
		l = 0;
		r = s->size - 1;
		while (l <= r)
		{
			mid = (r + l) / 2;
			if (arr[mid] == node->content)
			{
				node->content = mid;
				break ;
			}
			else if (arr[mid] < node->content)
				l = mid + 1;
			else
				r = mid - 1;
		}
		node = node->next;
	}
}

int	*fill_arr(int *arr, int size, int idx)
{
	int	i;
	int	*tmp;

	tmp = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
		tmp[i++] = arr[idx++];
	return (tmp);
}

void	sort(int *arr, int l, int mid, int r)
{
	int	i;
	int	j;
	int	k;
	int	*left;
	int	*right;

	i = 0;
	j = 0;
	k = l;
	left = fill_arr(arr, mid - l + 1, l);
	right = fill_arr(arr, r - mid, mid + 1);
	while (i < (mid - l + 1) && j < (r - mid))
	{
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < (mid - l + 1))
		arr[k++] = left[i++];
	while (j < r - mid)
		arr[k++] = right[j++];
	free(left);
	free(right);
}

void	merge_sort(int *arr, int l, int r)
{
	int	mid;

	if (l < r)
	{
		mid = l + ((r - l) / 2);
		merge_sort(arr, l, mid);
		merge_sort(arr, mid + 1, r);
		sort(arr, l, mid, r);
	}
}
