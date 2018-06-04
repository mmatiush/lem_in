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

# define INTERIM 0
# define START 1
# define END 2

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
	unsigned		color:2;
	unsigned		state:1;
	t_link			*link;
	t_room			*next;
};

typedef struct		s_queue
{
	t_room			*room_ptr;
	struct	s_queue	*next;
}					t_queue;

int					parse_input(t_room **rooms_ptr);
int					validate_str(char *str, t_room **rooms_ptr);

/*
** Validation
*/

int					validate_room(char *str, t_room **rooms_ptr);
int					validate_and_add_link(char *str, t_room **rooms_ptr);

int					ft_ptrtostrnum(char **str_arr);
int					ft_strisint(char *str);

t_room				*find_room(char *str, t_room *rooms_ptr);
t_link				*find_link(char *str, t_link *link);

int					add_room(char *str, t_room **rooms_ptr, unsigned room_type);
int					add_link(t_link **link, t_room *room);

#endif
