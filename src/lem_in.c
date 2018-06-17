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

void	print_extra(t_map *map, int flag, int n_rooms)
{
	while (map)
	{
		ft_printf("%s\n", map->str);
		map = map->next;
	}
	ft_printf("\n");
	if (flag & NROOM)
		ft_printf("Rooms number: [ %d ]\n\n", n_rooms);
}

void	null_lemin(t_room **rooms_ptr, t_queue **valid_paths, t_map **map, \
		int *n_rooms)
{
	g_front = NULL;
	g_rear = NULL;
	*rooms_ptr = NULL;
	*valid_paths = NULL;
	*map = NULL;
	*n_rooms = 0;
}

int		lem_in(int flag)
{
	t_room		*rooms_ptr;
	t_queue		*valid_paths;
	t_map		*map;
	int			n_ants;
	int			n_rooms;

	null_lemin(&rooms_ptr, &valid_paths, &map, &n_rooms);
	parse_input(&rooms_ptr, &n_ants, &map, &n_rooms);
	mark_rooms_near_start(rooms_ptr);
	find_paths(rooms_ptr, &valid_paths);
	update_paths_weight(valid_paths);
	if (!(valid_paths) && clear_lemin(&rooms_ptr, &valid_paths, &map))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	print_extra(map, flag, n_rooms);
	if (!(send_ants(n_ants, valid_paths, flag)) && clear_lemin(&rooms_ptr, \
		&valid_paths, &map))
		return (0);
	clear_lemin(&rooms_ptr, &valid_paths, &map);
	return (1);
}

void	read_flags(int *flag, int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-l"))
			*flag = *flag | LEAKS;
		if (ft_strequ(av[i], "-r"))
			*flag = *flag | NROOM;
		if (ft_strequ(av[i], "-s"))
			*flag = *flag | NSTEPS;
		if (ft_strequ(av[i], "-m"))
			*flag = *flag | MUSIC;
		i++;
	}
}

int		main(int ac, char *av[])
{
	int flag;

	flag = 0;
	read_flags(&flag, ac, av);
	if (!lem_in(flag))
	{
		if (flag & LEAKS)
			system("leaks --quiet lem_in");
		if (flag & MUSIC)
			system("afplay -t 2 -v 0.05% sounds/fail.wav");
		return (-1);
	}
	if (flag & LEAKS)
		system("leaks --quiet lem_in");
	if (flag & MUSIC)
		system("afplay -t 2 -v 0.2% sounds/success.wav");
	return (0);
}
