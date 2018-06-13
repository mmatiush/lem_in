/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:04:57 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:04:59 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		add_link(t_link **link, t_room *room)
{
	t_link	*temp;

	if (!(temp = (t_link*)malloc(sizeof(t_link))))
		return (0);
	temp->room_ptr = room;
	temp->next = *link;
	*link = temp;
	return (1);
}
