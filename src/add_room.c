#include "libft.h"
#include "lem_in.h"

int		add_room(char *str, t_room **rooms_ptr, unsigned room_type)
{
	t_room		*temp;
	char		*str_arr;

	if (!(str_arr = ft_strsplit(str, ' ')))
		return (0);
	if (!(temp = (t_room*)malloc(sizeof(t_room))))
		return (0);
	temp->next = *rooms_ptr;
	temp->name = str_arr[0];
	temp->coord_x = ft_atoi(str_arr[1]);
	temp->coord_y = ft_atoi(str_arr[2]);
	temp->room_type = room_type;
	temp->color = NEUTRAL;
	temp->state = OPEN;
	*rooms_ptr = temp;
	ft_free_str_arr(&str_arr[1]);
	free(str);
	return (1);
}
