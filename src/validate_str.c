#include "libft.h"
#include "lem_in.h"

#define ROOMS 0
#define LINKS 1

void		check_if_hash_command(char *str, unsigned *room_type_ptr)
{
	if (ft_strequ("##start", str))
		*room_type_ptr = START;
	else if (ft_strequ("##end", str))
		*room_type_ptr = END;
}

int		validate_str(char *str, t_room **rooms_ptr)
{
	static int		flag;
	static unsigned	room_type;

	if (!str)
		return (0);
	if (str[0] == '#')
	{
		check_if_hash_command(str, &room_type);
		return (1);
	}
	else if (flag == ROOMS && validate_room(str, rooms_ptr))
	{
		if (!(add_room(str, rooms_ptr, room_type)))
			return (0);
		room_type = INTERIM;
		return (1);
	}
	else if (validate_and_add_link(str, rooms_ptr))
	{
		flag = LINKS;
		return (1);
	}
	return (0);
}
