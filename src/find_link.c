/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:05:45 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:05:46 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_link		*find_link(char *str, t_link *link)
{
	while (link)
	{
		if (ft_strequ(link->room_ptr->name, str))
			return (link);
		link = link->next;
	}
	return (NULL);
}
