#include "libft.h"
#include "lem_in.h"

int		parse_input(t_room **rooms_ptr, int *ants)
{
	char	*buff;

	get_next_line(STDIN_FILENO, &buff);
	if (get_ants_num(ants, buff) == 0)
	{
		ft_printf("No ants\n");
		free(buff);
		return (0);
	}
	free(buff);
	while (get_next_line(STDIN_FILENO, &buff) == 1)
	{
		if (validate_str(buff, rooms_ptr) == 0)
		{
			ft_printf("ERROR\n");
			free(buff);
			return (0);
		}
	}
	// сделать проверку между стартом и концом
	return (1);
}
