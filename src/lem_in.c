#include "libft.h"
#include "lem_in.h"

int		main(void)
{
	t_room		*rooms_ptr;
	t_room		*valid_paths;
	int			ants;

	rooms_ptr = NULL;
	if (!(parse_input(&rooms_ptr, &ants)))
		return (0);
	if (!(valid_paths = find_paths(rooms_ptr)))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	print_rl(rooms_ptr);
	
}
