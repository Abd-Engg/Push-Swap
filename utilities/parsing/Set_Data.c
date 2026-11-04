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

t_strategy add_str(char **s,int *start)
{
    int counter = *start;
    t_strategy ret = adaptive;

    while (isflage(s[counter]))
    {
        ret = set_str(s[counter]);
        counter++;
    }
    *start =  counter;
    return ret;
}

int *add_data(char **s,int start,int size)
{
    int *ret = malloc(sizeof(int) * size);
    if (!ret)
        return NULL;
    int counter = 0;
    while (counter < size)
    {
        ret[counter] = ft_atoi(s[start + counter]);
        counter++;
    }
    return (ret);
}
