#include <stddef.h>
#include <stdio.h>
#include "ft_printf.h"

int        get_str_num(char **str_arr)
{
    int    num;

    num = 0;
    while (*str_arr)
	{
		num++;
		str_arr++;
		// printf("%d\n", num);
	}
    return (num);
}

int		ft_strisint(char *str)
{
	if (!str)
		return (0);
	if (ft_strequ(ft_itoa((ft_atoi(str))), str))
		return (1);
	else
		return (0);
}

int main()
{
	char **str_arr;
	char *str = "2147483649";
	str_arr = ft_strsplit(str, ' ');
	// ft_printf("str[0] = %s\n", str_arr[0]);
	// ft_printf("str[1] = %s\n", str_arr[1]);
	// ft_printf("str[2] = %s\n", str_arr[2]);
	// ft_printf("str[3] = %s\n", str_arr[3]);
	// printf("%d\n", get_str_num(str_arr));
	if (ft_strisint(str))
		ft_printf("%s IS int\n", str);
	else
		ft_printf("%s NOT int\n", str);
	return 0;
}