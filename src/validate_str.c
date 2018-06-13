/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:07:33 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:07:34 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

#define ROOMS 0
#define LINKS 1

static int	check_if_hash_command(char *str, unsigned *room_type_ptr)
{
	static	int flag;

	if (*room_type_ptr == START || *room_type_ptr == END)
		return (0);
	if (ft_strequ("##start", str))
	{
		if (flag == 2)
			return (0);
		flag++;
		*room_type_ptr = START;
	}
	else if (ft_strequ("##end", str))
	{
		if (flag == 2)
			return (0);
		flag++;
		*room_type_ptr = END;
	}
	return (1);
}

int			validate_str(char *str, t_room **rooms_ptr)
{
	static int		flag;
	static unsigned	room_type;

	if (!str)
		return (0);
	if (str[0] == '#')
	{
		if (!(check_if_hash_command(str, &room_type)))
			return (0);
		return (1);
	}
	else if (flag == ROOMS && validate_room(str, rooms_ptr))
	{
		if (!(add_room(str, rooms_ptr, room_type)))
			return (0);
		room_type = INTERIM;
		return (1);
	}
	else if (validate_and_add_link(str, rooms_ptr))
	{
		flag = LINKS;
		return (1);
	}
	return (0);
}
