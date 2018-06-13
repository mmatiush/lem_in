#include "libft.h"
#include "lem_in.h"

void	print_vp(t_queue *valid_paths)
{
	while (valid_paths)
	{
		ft_printf("PATH NAME %s - ", valid_paths->room_ptr->name);
		ft_printf("weight %d\n", valid_paths->room_ptr->weight);
		valid_paths = valid_paths->next;
	}
}

void	print_room_types(t_room *room)
{
	while (room)
	{
		ft_printf("room - %s, type - %d\n", room->name, room->room_type);
		room = room->next;
	}
}

void	update_paths_weight(t_queue *valid_paths)
{
	t_room	*room;
	t_room	*temp;
	int 	i;

	while (valid_paths)
	{
		i = 0;
		room = valid_paths->room_ptr;
		temp = valid_paths->room_ptr;
		while (room)
		{
			i++;
			room = room->path;
		}
		temp->weight = --i;
		valid_paths = valid_paths->next;
	}
}

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

void	add_new_ants(int *n_ants, t_ants **ants_ptr, t_queue *valid_paths)
{
	int				num;

	num = *n_ants;
	while(valid_paths && num > 0)
	{
		(*ants_ptr)->room_ptr = valid_paths->room_ptr;
		num -= valid_paths->room_ptr->weight;
		(*n_ants)--;
		valid_paths = valid_paths->next;
		(*ants_ptr) = (*ants_ptr)->next;
	}
}

void	delete_ant(t_ants** ants)
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
	while(temp && temp->room_ptr)
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

void	move_ants(int n_ants, t_ants *ants, t_queue *valid_paths)
{
	t_ants	*empty_ant_node;

	empty_ant_node = ants;
	while (ants)
	{
		move_existing_ants(&ants);
		add_new_ants(&n_ants, &empty_ant_node, valid_paths);
		print_ants(ants);
	}
}

void	teleport_ants(int n_ants, t_queue *valid_paths)
{
	int i;

	i = 1;
	while (i < n_ants)
	{
		ft_printf("L%d-%s ", i, valid_paths->room_ptr->path->name);
		i++;
	}
	ft_printf("L%d-%s\n", i, valid_paths->room_ptr->path->name);
}

int		send_ants(int n_ants, t_queue *valid_paths)
{
	t_ants	*ants;

	if (valid_paths->room_ptr->room_type == START && valid_paths->room_ptr->path->room_type == END)
	{
		teleport_ants(n_ants, valid_paths);
		return (1);
	}
	if (!(ants = create_ants_list(n_ants)))
		return (0);
	move_ants(n_ants, ants, valid_paths);
	return (1);
}

int		main(void)
{
	t_room		*rooms_ptr;
	t_queue		*valid_paths;
	int			n_ants;

	rooms_ptr = NULL;
	valid_paths = NULL;
	parse_input(&rooms_ptr, &n_ants);
	// print_room_types(rooms_ptr);
	find_paths(rooms_ptr, &valid_paths);
	update_paths_weight(valid_paths);
	if (!(valid_paths))
	{
		ft_printf("NO VALID PATHS\n");
		system ("leaks lem_in");
		return (1);
	}
	// else
		// print_vp(valid_paths);
	if (!(send_ants(n_ants, valid_paths)))
	{
		system ("leaks lem_in");
		return (1);
	}
	// print_rl(rooms_ptr);
	system ("leaks lem_in");
	return (0);
}
