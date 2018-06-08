#include "libft.h"
#include "lem_in.h"

int		main(void)
{
	t_room		*rooms_ptr;
	t_queue		*valid_paths;
	int			ants;

	rooms_ptr = NULL;
	valid_paths = NULL;
	if (!(parse_input(&rooms_ptr, &ants)))
		return (0);
	find_paths(rooms_ptr, &valid_paths);
	if (!(valid_paths))
	{
		ft_printf("NO VALID PATHS\n");
		return (0);
	}
	else
	{
		while (valid_paths)
		{
			ft_printf ("%s - ", valid_paths->room_ptr->name);
			ft_printf ("weight %d\n", valid_paths->room_ptr->weight);
			valid_paths = valid_paths->next;
		}
	}
//	send_ants(ants, valid_paths);
	// print_rl(rooms_ptr);
}
