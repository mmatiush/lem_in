#include "libft.h"
#include "lem_in.h"

void	print_vp(t_queue *valid_paths)
{
	while (valid_paths)
	{
		ft_printf("PATH NAME %s - ", valid_paths->room_ptr->name);
		ft_printf("weight %d\n", valid_paths->room_ptr->weight);
		valid_paths = valid_paths->next;
	}
}

void	print_room_types(t_room *room)
{
	while (room)
	{
		ft_printf("room - %s, type - %d\n", room->name, room->room_type);
		room = room->next;
	}
}

void	update_paths_weight(t_queue *valid_paths)
{
	t_room	*room;
	t_room	*temp;
	int 	i;

	while (valid_paths)
	{
		i = 1;
		room = valid_paths->room_ptr;
		temp = valid_paths->room_ptr;
		while (room)
		{
			i++;
			room = room->path;
		}
		temp->weight = --i;
		valid_paths = valid_paths->next;
	}
}

void	send_ants(int ants, t_queue *valid_paths)
{
	if (valid_paths->room_ptr->path->room_type == START)
		return ();
}

int		main(void)
{
	t_room		*rooms_ptr;
	t_queue		*valid_paths;
	int			ants;

	rooms_ptr = NULL;
	valid_paths = NULL;
	if (!(parse_input(&rooms_ptr, &ants)))
		return (0);
	print_room_types(rooms_ptr);
	find_paths(rooms_ptr, &valid_paths);
	update_paths_weight(valid_paths);
	if (!(valid_paths))
	{
		ft_printf("NO VALID PATHS\n");
		return (0);
	}
	else
	{
		while (valid_paths)
		{
			print_vp(valid_paths);
		}
	}
	send_ants(ants, valid_paths);
	print_rl(rooms_ptr);
}
