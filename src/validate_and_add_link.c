#include "libft.h"
#include "lem_in.h"

int		validate_and_add_link(char *str, t_room **rooms_ptr)
{
	char	**str_arr;
	t_room	*room1;
	t_room	*room2;

	if (ft_strchr(str, ' '))
		return (0);
	str_arr = ft_strsplit(str, '-');
	if (ft_ptrtostrnum(str_arr) != 2 && ft_free_str_arr(&str_arr))
		return (0);
	if (ft_strequ(str_arr[0], str_arr[1]) && ft_free_str_arr(&str_arr))
		return (0);
	if ((!(room1 = find_room(str_arr[0], *rooms_ptr)) || \
		!(room2 = find_room(str_arr[1], *rooms_ptr))) && \
		ft_free_str_arr(&str_arr))
		return (0);
	if (find_link(room2->name, room1->link) && ft_free_str_arr(&str_arr))
	{
		ft_printf("Link already exists\n");
		return (0);
	}
	if (!(add_link(&room1->link, room2)) && ft_free_str_arr(&str_arr))
		return (0);
	if(!(add_link(&room2->link, room1)) && ft_free_str_arr(&str_arr))
		return (0);
	ft_free_str_arr(&str_arr);
	return (1);
}
