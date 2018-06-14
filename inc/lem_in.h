/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:49:14 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:49:16 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define INTERIM 0
# define START 1
# define END 2
# define NEAR_START 3

# define WHITE 0
# define GREY 1
# define BLACK 2

typedef struct s_room	t_room;

typedef struct		s_link
{
	t_room			*room_ptr;
	struct s_link	*next;
}					t_link;

struct				s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				weight;
	unsigned		room_type;
	unsigned		color;
	t_room			*path;
	t_link			*link;
	t_room			*next;
};

typedef struct		s_queue
{
	t_room			*room_ptr;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_ants
{
	int				name;
	t_room			*room_ptr;
	struct s_ants	*next;
}					t_ants;

typedef struct		s_map
{
	char			*str;
	struct s_map	*next;
}					t_map;

t_queue				*g_front;
t_queue				*g_rear;

int					parse_input(t_room **room_ptr, int *ants, t_map **map);
int					validate_str(char *str, t_room **room_ptr);

/*
** Validation
*/

int					validate_room(char *str, t_room **room_ptr);
int					validate_and_add_link(char *str, t_room **room_ptr);
int					get_ants_num(int *ants, char *str, t_map **map);

int					ft_ptrtostrnum(char **str_arr);
int					find_paths(t_room *room, t_queue **valid_paths);

t_room				*find_room(char *str, t_room *room);
t_link				*find_link(char *str, t_link *link);

int					add_room(char *str, t_room **room_ptr, unsigned room_type);
int					add_link(t_link **link, t_room *room);

int					mark_rooms_near_start(t_room *room);

int					enqueue(t_room *room, t_room *prev_room);
t_room				*dequeue(void);
int					queue_is_empty(void);
void				add_rooms_to_queue(t_link *link, t_room *temp);
void				clean_queue(void);

void				update_paths_weight(t_queue *valid_paths);

t_ants				*create_ants_list(int n_ants);
void				add_new_ants(int *n_ants, t_ants **ants_ptr, \
					t_queue *valid_paths);
void				delete_ant(t_ants **ants);
void				move_existing_ants(t_ants **ants);
void				print_ants(t_ants *ants);
void				move_ants(int n_ants, t_ants *ants, t_queue *valid_paths);
void				teleport_ants(int n_ants, t_queue *valid_paths);
int					send_ants(int n_ants, t_queue *valid_paths);

int					add_to_map(char *str, t_map **map);

int					clear_lemin(t_room **rooms_ptr, t_queue **valid_paths, \
					 t_map **map);
#endif
