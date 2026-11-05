#include "../../header_files/pushswap.h"
#include "../../header_files/libft.h"

t_strategy	set_str(char *s)
{
	if (ft_strcmp(s, "--simple") == 0)
		return (simple);
	if (ft_strcmp(s, "--medium") == 0)
		return (medium);
	if (ft_strcmp(s, "--complex") == 0)
		return (complex);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (adaptive);
	return (NONE);
}

t_strategy add_str(char **s, int start)
{
    t_strategy	ret;

	ret = adaptive;
    if (isflag(s[start]))
    {
        ret = set_str(s[start]);
        start++;
    }
    return (ret);
}

long *add_data(char **s,int start, parsing *return_value)
{
    long	*ret;
	int		size;

	size = return_value->size;
	ret = malloc(sizeof(long) * size);
    if (!ret)
        return (NULL);
    int counter = 0;
    while (counter < size)
    {
        ret[counter] = ft_atoi(s[start + counter]);
		if (ret[counter] > int_max || ret[counter] < int_min)
			return_value->error = 1;
        counter++;
    }
    return (ret);
}
