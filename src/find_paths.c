#include "libft.h"
#include "lem_in.h"

t_room	*get_start(t_room *room)
{
	while(room)
	{
		if (room->room_type == START)
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_room	*get_end(t_room *room)
{
	while(room)
	{
		if (room->room_type == END)
			return (room);
		room = room->next;
	}
	return (NULL);
}

int		find_paths(t_room *room)
{
	t_room	*temp;

	g_front = NULL;
	g_rear = NULL;
	temp = get_end(room);
	enque()
	while (!isempty())
	{
		
	}
}