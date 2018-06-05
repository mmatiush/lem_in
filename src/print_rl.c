#include "libft.h"
#include "lem_in.h"

int		print_rl(t_room *room)
{
	while (room)
	{
		ft_printf("[%s]", room->name);
		while (room->link)
		{
			ft_printf("-[%s]", room->link->room_ptr->name);
			room->link = room->link->next;
		}
		room = room->next;
		ft_printf("\n");
	}
	return (0);
}
