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

static void	find_rooms_near_start(t_room *room)
{
	t_room	*start;

	start = get_start(room);
	while(start->link)
	{
		start->link->room_ptr->room_type = NEAR_START;
		start = start->link->next;
	}
}

void	add_path(t_queue )
{
	
}

int		find_paths(t_room *room)
{
	t_room	*end;
	t_room	*temp;
	t_room	*valid_paths;

	g_front = NULL;
	g_rear = NULL;
	end = get_end(room);
	enque(end, NULL);
	find_rooms_near_start(room);
	while (!queue_is_empty())
	{
		temp = dequeue();
		if (temp->room_type == NEAR_START)
		{
			add_path(&valid_paths);
		}
	}
}
