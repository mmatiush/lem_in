/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:05:13 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:05:14 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static void	clear_room(t_room **rooms_ptr)
{
	t_room	*temp;

	if (rooms_ptr == NULL)
		return ;
	while (*rooms_ptr)
	{
		temp = *rooms_ptr;
		*rooms_ptr = (*rooms_ptr)->next;
		free(temp->name);
		free(temp);
	}
}

static void	clear_queue(t_queue **valid_paths)
{
	t_queue	*temp;

	if (valid_paths == NULL)
		return ;
	while (*valid_paths)
	{
		temp = *valid_paths;
		*valid_paths = (*valid_paths)->next;
		free(temp);
	}
}

static void	clea_map(t_map **map)
{
	t_map	*temp;

	if (map == NULL)
		return ;
	while (*map)
	{
		temp = *map;
		*map = (*map)->next;
		free(temp->str);
		free(temp);
	}
}

int		clear_lemin(t_room **rooms_ptr, t_queue **valid_paths, t_map **map)
{
	clear_room(rooms_ptr);
	clear_queue(valid_paths);
	clea_map(map);
	return (1);
}
