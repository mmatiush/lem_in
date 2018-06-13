/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_rooms_near_start.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 22:35:03 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 22:35:04 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static t_room	*get_start_room(t_room *room)
{
	while (room)
	{
		if (room->room_type == START)
			return (room);
		room = room->next;
	}
	return (NULL);
}

int				mark_rooms_near_start(t_room *room)
{
	t_room	*start;
	t_link	*link;

	if (!(start = get_start_room(room)))
	{
		ft_printf("No start room\n");
		return (0);
	}
	if (!(link = start->link))
	{
		ft_printf("Start room has no links\n");
		return (0);
	}
	while (link)
	{
		if (link->room_ptr->room_type != END)
			link->room_ptr->room_type = NEAR_START;
		link = link->next;
	}
	return (1);
}
