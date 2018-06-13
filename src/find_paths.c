/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:06:09 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:06:10 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_room		*get_end_room(t_room *room)
{
	while (room)
	{
		if (room->room_type == END)
			return (room);
		room = room->next;
	}
	return (NULL);
}

void		make_path_black(t_room *room)
{
	while (room->room_type != END)
	{
		room->color = BLACK;
		room = room->path;
	}
}

static int	add_valid_path(t_room *room, t_queue **valid_paths)
{
	t_queue *temp;
	t_queue *last_path;

	if (!(temp = (t_queue*)malloc(sizeof(t_queue))))
		return (0);
	make_path_black(room);
	temp->room_ptr = room;
	temp->next = NULL;
	if (*valid_paths == NULL)
	{
		*valid_paths = temp;
		return (1);
	}
	last_path = *valid_paths;
	while (last_path->next != NULL)
		last_path = last_path->next;
	last_path->next = temp;
	return (1);
}

void		make_grey_rooms_white(t_room *room)
{
	while (room)
	{
		if (room->color == GREY)
			room->color = WHITE;
		room = room->next;
	}
}

int			find_paths(t_room *room, t_queue **valid_paths)
{
	t_room	*end;
	t_room	*temp;
	int		flag;

	g_front = NULL;
	g_rear = NULL;
	if (!(end = get_end_room(room)))
		return (0);
	flag = 1;
	while (flag == 1)
	{
		enqueue(end, NULL);
		flag = 0;
		while (!queue_is_empty())
		{
			if ((temp = dequeue()) && (temp->room_type == NEAR_START || temp->room_type == START))
			{
				add_valid_path(temp, valid_paths);
				make_grey_rooms_white(room);
				clean_queue();
				flag = 1;
				break ;
			}
			if (temp)
				add_rooms_to_queue(temp->link, temp);
		}
	}
	return (1);
}
