/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:05:52 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:05:53 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		get_ants_num(int *ants, char *str, t_map **map)
{
	if (!str)
		return (0);
	if (!ft_strisint(str) || (*ants = ft_atoi(str)) <= 0)
	{
		free(str);
		return (0);
	}
	add_to_map(str, map);
	return (1);
}
