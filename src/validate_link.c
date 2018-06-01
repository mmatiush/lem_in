#include "libft.h"
#include "lem_in.h"

int		validate_link(char *str, t_room **rooms_ptr)
{
	char	**str_arr;

	if (ft_strchr(str, ' '))
		return (0);
	str_arr = ft_strsplit(str, '-');
	if (get_str_num(str_arr) != 2)
		return (0);
	if (check_if_room_exists(str_arr[0], *rooms_ptr) && check_if_room_exists(str_arr[1], *rooms_ptr)) // ДОПИСАТЬ ЗДЕСЬ ПРОВЕРКУ НА СУЩЕСТОВАНИЕ КОМНАТЫ
		return (1);
	return (0);
}
