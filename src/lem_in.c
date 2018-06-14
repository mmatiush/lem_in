/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:05:13 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:05:14 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void	print_map(t_map *map)
{
	while (map)
	{
		ft_printf("%s\n", map->str);
		map = map->next;
	}
	ft_printf("\n");
}

int		lem_in(void)
{
	t_room		*rooms_ptr;
	t_queue		*valid_paths;
	t_map		*map;
	int			n_ants;

	map = NULL;
	rooms_ptr = NULL;
	valid_paths = NULL;
	parse_input(&rooms_ptr, &n_ants, &map);
	mark_rooms_near_start(rooms_ptr);
	find_paths(rooms_ptr, &valid_paths);
	update_paths_weight(valid_paths);
	if (!(valid_paths) && clear_lemin(&rooms_ptr, &valid_paths, &map))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	print_map(map);
	if (!(send_ants(n_ants, valid_paths)) && clear_lemin(&rooms_ptr, &valid_paths, &map))
		return (0);
	clear_lemin(&rooms_ptr, &valid_paths, &map);
	return (1);
}

int		main(void)
{
	// int flag;

	if (!lem_in())
	{
		// if (flag == LEAKS)
			system ("leaks --quiet lem_in");
		return (-1);
	}
	// if (flag == LEAKS)
		system ("leaks --quiet lem_in");
	return (0);
}
