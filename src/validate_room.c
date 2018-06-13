/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:06:00 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:06:02 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static int	space_num(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	return (i);
}

int			ft_ptrtostrnum(char **str_arr)
{
	int	num;

	num = 0;
	if (!(str_arr))
		return (0);
	while (*str_arr)
	{
		num++;
		str_arr++;
	}
	return (num);
}

int			validate_room(char *str, t_room **rooms_ptr)
{
	char	**str_arr;

	str_arr = NULL;
	if (str[0] == 'L')
		return (0);
	if (ft_strchr(str, '-'))
		return (0);
	if (space_num(str) != 2)
		return (0);
	str_arr = ft_strsplit(str, ' ');
	if (ft_ptrtostrnum(str_arr) != 3 && ft_free_str_arr(&str_arr))
		return (0);
	if (find_room(str_arr[0], *rooms_ptr) && ft_free_str_arr(&str_arr))
		return (0);
	if ((!ft_strisint(str_arr[1]) || !ft_strisint(str_arr[2]))\
		&& ft_free_str_arr(&str_arr))
		return (0);
	ft_free_str_arr(&str_arr);
	return (1);
}
