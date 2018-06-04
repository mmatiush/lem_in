#include "libft.h"
#include "lem_in.h"

t_link		*find_link(char *str, t_link *link)
{
	while (link)
	{
		if (ft_strequ(link->room_ptr->name, str))
			return (link);
		link = link->next;
	}
	return (NULL);
}
