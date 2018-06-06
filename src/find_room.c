#include "libft.h"
#include "lem_in.h"

t_room		*find_room(char *str, t_room *room)
{
	if (!room)
		return (NULL);
	while (room)
	{
		if (ft_strequ(room->name, str))
			return (room);
		room = room->next;
	}
	return (NULL);
}
