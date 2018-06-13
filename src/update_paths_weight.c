/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths_weight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:05:20 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:05:21 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void	update_paths_weight(t_queue *valid_paths)
{
	t_room	*room;
	t_room	*temp;
	int		i;

	while (valid_paths)
	{
		i = 0;
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
