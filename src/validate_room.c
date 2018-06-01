#include "libft.h"
#include "lem_in.h"

int		space_num(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	return (i);
}

int		get_str_num(char **str_arr)
{
	int	num;

	num = 0;
	while (*str_arr)
	{
		num++;
		str_arr++;
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

int		validate_room(char *str, t_room **rooms_ptr)
{
	char	**str_arr;

	if (str[0] == 'L')
		return (0);
	if (str_space_num(str) != 2)
		return (0);
	if (ft_strchr(str, '-'))
		return (0);
	// if (check_room_(str) != 1)					???
	// 	return (0);
	str_arr = ft_strsplit(str, ' ');
	if (get_str_num(str_arr) != 3)
		return (0);
	if (check_if_room_exists(str_arr[0], rooms_ptr)) // ДОПИСАТЬ ЗДЕСЬ ПРОВЕРКУ НА СУЩЕСТОВАНИЕ КОМНАТЫ
		return (0);
	if (!ft_strisint(str_arr[1]) || !ft_strisint(str_arr[2]))
		return (0);
	ft_free_str_arr(&str_arr);
	return (1);
}
