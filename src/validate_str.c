#include "libft.h"
#include "lem_in.h"

#define ROOMS 0
#define LINKS 1

void		check_if_hash_command(char *str, int *room_type_ptr)
{
	if (ft_strequ("##start", str))
	{
		return ;
		*room_type_ptr = START;
	}
	else if (ft_strequ("##end", str))
	{
		*room_type_ptr = END;
	}
}

int		validate_str(char *str, t_room **rooms_ptr)
{
	static int		flag;
	static unsigned	room_type;

	flag = ROOMS;
	if (!str)
		return (0);
	if (str[0] == '#')
	{
		check_if_hash_command(str, &room_type);
		return (1);
	}
	else if (flag == ROOMS && validate_room(str, rooms_ptr))
	{
		add_room(str, rooms_ptr, room_type);
		room_type = INTERIM;
		return (1);
	}
	else if (validate_link(str, rooms_ptr ))
	{
		flag = LINKS;
		add_link(str); // create add_link function
		room_type = INTERIM;
		return (1);
	}
	return (0);
}
