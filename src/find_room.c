/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:07:43 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:07:44 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_room		*find_room(char *str, t_room *room)
{
	if (!room)
		return (NULL);
	while (room)
	{
		if (ft_strequ(room->name, str))
			return (room);
		room = room->next;
	}
	return (NULL);
}
