#include "libft.h"
#include "lem_in.h"

int		enqueue(t_room *room, t_room *prev_room)
{ 
	t_queue		*temp;

	if (!(temp = (t_queue*)malloc(sizeof(t_queue))))
		return (0);
	temp->room_ptr = room;
	room->color = GREY;
	temp->next = NULL;
	// if (prev_room && room->room_type != START)
	if (prev_room)
	{
		room->path = prev_room;
		room->weight = prev_room->weight + 1;
	}
	if (g_front == NULL && g_rear == NULL)
	{
		g_front = temp;
		g_rear = temp;
		return (1);
	}
	g_rear->next = temp;
	g_rear = temp;
	return (1);
}

t_room		*dequeue(void)
{
	t_queue		*temp;
	t_room		*room;

	temp = g_front;
	if (g_front == NULL)
		return (NULL);
	if (g_front == g_rear)
	{
		g_front = NULL;
		g_rear = NULL;
	}
	else
		g_front = g_front->next;
	room = temp->room_ptr;
	free(temp);
	return (room);
}

int		queue_is_empty(void)
{
	if (g_front == NULL)
		return (1);
	return (0);
}
