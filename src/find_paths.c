#include "libft.h"
#include "lem_in.h"

t_room		*get_end_room(t_room *room)
{
	while(room)
	{
		if (room->room_type == END)
			return (room);
		room = room->next;
	}
	return (NULL);
}

void		make_path_black(t_room *room)
{
	while (room->room_type != START)
	{
		room->color = BLACK;
		room = room->path;
	}
}

static int	is_path_black(t_room *room)
{
	while (room->room_type != START && room->color != BLACK)
	{
		if (room->color == BLACK)
			return (1);
		room = room->path;
	}
	return (0);
}

static int	add_valid_path(t_room *room, t_queue **valid_paths)
{
	t_queue *temp;
	t_queue *last_path;

	if (!(temp = (t_queue*)malloc(sizeof(t_queue))))
		return (0);
	make_path_black(room);
	temp->room_ptr = room;
	temp->next = NULL;
	if (*valid_paths == NULL)
	{
		*valid_paths = temp;
		return (1);
	}
	last_path = *valid_paths;
	while (last_path->next != NULL)
		last_path = last_path->next;
	last_path->next = temp;
	return (1);
}

int			find_paths(t_room *room, t_queue **valid_paths)
{
	t_room	*end;
	t_room	*temp;
	t_link	*link;

	g_front = NULL;
	g_rear = NULL;
	if (!(end = get_end_room(room)))
		return (0);
	enqueue(end, NULL);
	while (!queue_is_empty())
	{
		temp = dequeue();
		if (temp->room_type == NEAR_START)
		{
			add_valid_path(temp, valid_paths);
			continue ;
		}
		link = temp->link;
		while (link)
		{
			if (link->room_ptr->color != BLACK)
				enqueue(link->room_ptr, temp);
			link = link->next;
		}
	}
	return (1);
}
