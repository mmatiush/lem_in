#include "libft.h"
#include "lem_in.h"

/*
** Check if there exists any room with the same coordinates.
*/

static int	validate_coords(t_room *room, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	while (room)
	{
		if (room->coord_x == x && room->coord_y == y)
			return (0);
		room = room->next;
	}
	return (1);
}

int			add_room(char *str, t_room **rooms_ptr, unsigned room_type)
{
	t_room		*temp;
	char		**str_arr;

	if (!(str_arr = ft_strsplit(str, ' ')))
		return (0);
	if (!(temp = (t_room*)malloc(sizeof(t_room))))
		return (0);
	if (!(temp->name = ft_strdup(str_arr[0])))
		return (0);
	temp->coord_x = ft_atoi(str_arr[1]);
	temp->coord_y = ft_atoi(str_arr[2]);
	if (!(validate_coords(*rooms_ptr, temp->coord_x, temp->coord_y)))
		return (0);
	temp->weight = 0;
	temp->room_type = room_type;
	temp->color = WHITE;
	temp->link = NULL;
	temp->path = NULL;
	temp->next = *rooms_ptr;
	*rooms_ptr = temp;
	ft_free_str_arr(&str_arr);
	return (1);
}
