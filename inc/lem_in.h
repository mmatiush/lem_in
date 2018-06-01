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

#define INTERIM 0
#define START 1
#define END 2

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
	int				weight;
	int				coord_x;
	int				coord_y;
	unsigned		color:2;
	unsigned		state:1;
	unsigned		room_type:2;
	t_link			*link;
	t_room			*next;
};

typedef struct		s_queue
{
	t_room			*room_ptr;
	struct	s_queue	*next; 
}					t_queue;

int					parse_input();
int					validate_str(char *str, t_room **rooms_ptr);
int					validate_room(char *str, t_room **rooms_ptr);
int					validate_link(char *str, t_room **rooms_ptr);

int					add_room(char *str, t_room **rooms_ptr, unsigned room_type);




int					get_str_num(char **str_arr);


#endif
