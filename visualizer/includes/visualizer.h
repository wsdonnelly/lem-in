/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:19:07 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/25 13:26:19 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>

# define KEYPAD4		0x56
# define KEYPAD5		0x57
# define KEYPAD6		0x58
# define KEYPAD7		0x59
# define KEYPAD8		0x5B
# define KEYPAD9		0x5C
# define LEFTARROW		0x7B
# define RIGHTARROW		0x7C
# define DOWNARROW		0x7D
# define UPARROW		0x7E
# define Q				0x0C
# define W				0x0D
# define MINUS			0x1B
# define EQUAL			0x18
# define P				0x23
# define SPACE			0x31
# define ESCAPE			0x35

# define TRUE 1
# define FALSE 0

typedef struct s_info
{
	int		num_ants;
	int		num_rooms;
	char	*start;
	char	*end;
}				t_info;

typedef struct s_link
{
	int				link;
	struct s_link	*next;
}				t_link;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
	int		z;
	t_link	*link;
	struct s_point point;
}				t_room;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	//controls
	int		zoom;
	int		x_offset;
	int		y_offset;
	double	alpha;
	double	beta;
	double	gamma;
	int		color;
	//room and info
	struct s_room	*room_arr;
	struct s_info	*info;
}				t_data;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}				t_line;

/*
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**map;
	int		height;
	int		width;
	int		elev;
	int		zoom;
	int		x_offset;
	int		y_offset;
	double	alpha;
	double	beta;
	double	gamma;
	int		projection;
	int		color;

}				t_data;
*/




void	read_in_info(t_info *info, t_room **room_arr);
void	read_rooms(t_info *info, t_room **room_arr, char *line, int *max_coordiante);
void	add_links(t_room **room_arr, char *line, int num_rooms);

t_room *add_room(t_info *info);
void	draw_graph(t_data *data);
int	controls(int key, t_data *data);
//hash-map
int	hash_map(char *name, t_info *info, t_room **room_arr);
int	hasher(char *name, int num_rooms);
int	lookup(char *name, int num_rooms, t_room **room_arr);

void	make_line(t_data *data, t_point a, t_point b);

void	rotate(t_point *a, t_data *data);

void	free_data(t_data *data);
void	free_str_arr(char **arr);
void exit_error(t_data *data, char *message);
#endif