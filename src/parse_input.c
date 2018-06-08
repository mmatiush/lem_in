#include "libft.h"
#include "lem_in.h"

t_room		*get_start_room(t_room *room)
{
	while(room)
	{
		if (room->room_type == START)
			return (room);
		room = room->next;
	}
	return (NULL);
}

static int	mark_rooms_near_start(t_room *room)
{
	t_room	*start;
	t_link	*link;

	if (!(start = get_start_room(room)))
	{
		ft_printf("No start room\n");
		return (0);
	}
	if (!(link = start->link))
	{
		ft_printf("Start room has no links\n");
		return (0);
	}
	while(link)
	{
		link->room_ptr->room_type = NEAR_START;
		link = link->next;
	}
	return (1);
}

int		parse_input(t_room **rooms_ptr, int *ants)
{
	char	*buff;

	buff = NULL;
	get_next_line(STDIN_FILENO, &buff);
	if (get_ants_num(ants, buff) == 0)
		return (0);
	while (get_next_line(STDIN_FILENO, &buff) == 1)
	{
		if (buff[0] == '\0')
		{
			free (buff);
			break ;
		}
		if (validate_str(buff, rooms_ptr) == 0)
		{
			ft_printf("ERROR\n");
			free(buff);
			return (0);
		}
		free(buff);
	}
	if (!(mark_rooms_near_start(*rooms_ptr)))
		return (0);
	return (1);
}
