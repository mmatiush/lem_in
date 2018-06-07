/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:49:14 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:49:16 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

// Room type

# define INTERIM 0
# define START 1
# define END 2
# define NEAR_START 3

// Visited

# define FALSE 0
# define TRUE 1

# define NEUTRAL 0
# define BLACK 1
# define WHITE 2

# define OPEN 0
# define CLOSED 1

typedef struct		s_room t_room;

typedef struct		s_link
{
	t_room			*room_ptr;
	struct	s_link	*next;
}					t_link;

struct				s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				weight;
	unsigned		room_type:2;
	unsigned		state:1;
	unsigned		visited:1;
	t_room			*path;
	t_link			*link;
	t_room			*next;
};

typedef struct		s_queue
{
	t_room			*room_ptr;
	struct	s_queue	*next;
}					t_queue;

t_queue				*g_front;
t_queue				*g_rear;

int					parse_input(t_room **room_ptr, int *ants);
int					validate_str(char *str, t_room **room_ptr);

/*
** Validation
*/

int					validate_room(char *str, t_room **room_ptr);
int					validate_and_add_link(char *str, t_room **room_ptr);
int					get_ants_num(int *ants, char *str);

int					ft_ptrtostrnum(char **str_arr);

t_room				*find_room(char *str, t_room *room);
t_link				*find_link(char *str, t_link *link);

int					add_room(char *str, t_room **room_ptr, unsigned room_type);
int					add_link(t_link **link, t_room *room);

int					print_rl(t_room *room);

int					enqueue(t_room *room, t_room *prev_room);
t_room				*dequeue(void);
int					queue_is_empty(void);


#endif
