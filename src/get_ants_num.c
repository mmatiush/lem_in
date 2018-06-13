#include "libft.h"
#include "lem_in.h"

int		get_ants_num(int *ants, char *str)
{
	if (!str)
		return (0);
	if (!ft_strisint(str) || (*ants = ft_atoi(str)) <= 0)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
