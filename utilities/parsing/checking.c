#include "../../header_files/pushswap.h"
#include "../../header_files/libft.h"
#include <stdio.h>

int	is_bench(char *s)
{
	return (ft_strcmp(s, "--bench") == 0);
}

int	isflag(char *s)
{
	if (!s)
		return (0);
	return (set_str(s) != NONE || is_bench(s));
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int check(char **s,int size)
{
    int counter = 0;
    int num_flags = 0;
    while (counter < size && isflag(s[counter]))
    {
        num_flags++;
        counter++;      
    }
    if (num_flags > 2 || counter > size)
        return (0);
    while (counter < size)
    {
        if(!is_number(s[counter]))
            return (0);
        counter++;
    }
    return (1);
}

int isdup(int *data,int size)
{ 
    int i = 0;
    int j = 0;
    while (i < size)
    {
        j = i + 1;
        while ( j < size)
        {
            if (data[i] == data[j])
                return (1);
           j++; 
        }
        i++;
    }
    return (0);
}
