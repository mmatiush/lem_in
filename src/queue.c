#include "libft.h"
#include "lem_in.h"

int		enqueue(t_room *room)
{
	t_queue		*temp;

	if (!(temp = (t_queue*)malloc(sizeof(t_queue))))
		return (0);
	temp->room_ptr = room;
	temp->next = NULL;
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

void	dequeue()
{

}

t_queue	*front()
{
	return ();
}