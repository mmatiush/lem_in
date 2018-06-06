#include "libft.h"
#include "lem_in.h"

int		get_ants_num(int *ants, char *str)
{
	if (!ft_strisint(str) || !str)
		return (0);
	*ants = ft_atoi(str);
	if (*ants <= 0)
		return (0);
	return (1);
}
