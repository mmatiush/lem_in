#include "libft.h"
#include "lem_in.h"

t_room		*find_room(char *str, t_room *rooms_ptr)
{
	if (!rooms_ptr)
		return (NULL);
	while (rooms_ptr)
	{
		if (ft_strequ(rooms_ptr->name, str))
			return (rooms_ptr);
		rooms_ptr = rooms_ptr->next;
	}
	return (NULL);
}
