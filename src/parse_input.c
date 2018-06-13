/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:05:52 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:05:53 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		add_to_map(char *str, t_map **map)
{
	t_map	*temp;
	t_map	*last_node;

	if (!(temp = (t_map *)malloc(sizeof(t_map))))
		return (0);
	temp->str = str;
	temp->next = NULL;
	if (*map == NULL)
	{
		*map = temp;
		return (1);
	}
	last_node = *map;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = temp;
	return (1);
}

int		parse_input(t_room **rooms_ptr, int *ants, t_map **map)
{
	char	*buff;

	buff = NULL;
	get_next_line(STDIN_FILENO, &buff);
	if (get_ants_num(ants, buff, map) == 0)
		return (0);
	while (get_next_line(STDIN_FILENO, &buff) == 1)
	{
		if (buff[0] == '\0')
		{
			free(buff);
			break ;
		}
		if (validate_str(buff, rooms_ptr) == 0)
		{
			free(buff);
			return (0);
		}
		add_to_map(buff, map);
	}
	return (1);
}
