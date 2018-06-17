/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:05:29 by mmatiush          #+#    #+#             */
/*   Updated: 2018/06/13 19:05:30 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void	add_new_ants(int *n_ants, t_ants **ants_ptr, t_queue *valid_paths)
{
	int				num;

	num = *n_ants;
	while (valid_paths && num > 0)
	{
		(*ants_ptr)->room_ptr = valid_paths->room_ptr;
		num -= valid_paths->room_ptr->weight;
		(*n_ants)--;
		valid_paths = valid_paths->next;
		(*ants_ptr) = (*ants_ptr)->next;
	}
}

void	delete_ant(t_ants **ants)
{
	t_ants	*temp;

	temp = *ants;
	free(temp);
	*ants = (*ants)->next;
}

void	move_existing_ants(t_ants **ants)
{
	t_ants	*temp;

	temp = *ants;
	while (temp && temp->room_ptr)
	{
		if (temp->room_ptr->room_type == END)
		{
			temp = temp->next;
			delete_ant(ants);
		}
		else
		{
			temp->room_ptr = temp->room_ptr->path;
			temp = temp->next;
		}
	}
}

void	teleport_ants(int n_ants, t_queue *valid_paths, int flag)
{
	int i;

	i = 1;
	while (i < n_ants)
	{
		ft_printf("L%d-%s ", i, valid_paths->room_ptr->path->name);
		i++;
	}
	ft_printf("L%d-%s\n", i, valid_paths->room_ptr->path->name);
	if (flag & NSTEPS)
		ft_printf("\nSteps taken: [ 1 ]\n\n");
}

void	move_ants(int n_ants, t_ants *ants, t_queue *valid_paths, int flag)
{
	t_ants	*empty_ant_node;
	int		n_steps;

	n_steps = 0;
	empty_ant_node = ants;
	while (ants)
	{
		move_existing_ants(&ants);
		add_new_ants(&n_ants, &empty_ant_node, valid_paths);
		print_ants(ants);
		n_steps++;
	}
	if (flag & NSTEPS)
		ft_printf("\nSteps taken: [ %d ]\n\n", --n_steps);
}
