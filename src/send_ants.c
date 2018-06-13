/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:08:02 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:08:03 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_ants	*create_ants_list(int n_ants)
{
	t_ants	*ants;
	t_ants	*temp;

	ants = NULL;
	while (n_ants > 0)
	{
		if (!(temp = (t_ants*)malloc(sizeof(t_ants))))
			return (NULL);
		temp->name = n_ants;
		temp->room_ptr = NULL;
		temp->next = ants;
		ants = temp;
		n_ants--;
	}
	return (ants);
}

void	print_ants(t_ants *ants)
{
	if (ants == NULL)
		return ;
	while (ants && ants->room_ptr)
	{
		ft_printf("L%d-%s", ants->name, ants->room_ptr->name);
		ants = ants->next;
		if (ants && ants->room_ptr)
			ft_printf(" ");
	}
	ft_printf("\n");
}

int		send_ants(int n_ants, t_queue *valid_paths)
{
	t_ants	*ants;

	if (valid_paths->room_ptr->room_type == START &&\
		valid_paths->room_ptr->path->room_type == END)
	{
		teleport_ants(n_ants, valid_paths);
		return (1);
	}
	if (!(ants = create_ants_list(n_ants)))
		return (0);
	move_ants(n_ants, ants, valid_paths);
	return (1);
}
