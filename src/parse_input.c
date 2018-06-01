#include "libft.h"
#include "lem_in.h"

int		parse_input(t_room **rooms_ptr)
{
	char	*buff;

	while (get_next_line(STDIN_FILENO, &buff) == 1)
	{
		if (validate_str(buff, rooms_ptr) == 0)
		{
			ft_printf("ERROR\n");
			return (0);
		}
		free(buff);
	}
	// сделать проверку между стартом и концом
	return (1);
}
