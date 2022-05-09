/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:19:07 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/09 15:16:24 by wdonnell         ###   ########.fr       */
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
# define MINUS			0x1B
# define EQUAL			0x18
# define SPACE			0x31
# define ESCAPE			0x35
# define X				0x07
# define Y				0x10

# define TRUE 1
# define FALSE 0

# define COLOR1 0x00FF8080
# define COLOR2 0x0000FFFF
# define COLOR3 0x00FF00FF
# define COLOR4 0x00FFEE58
# define COLOR5 0x00FF7043
# define COLOR6 0x00F44336
# define COLOR7 0x007B1FA2
# define COLOR8 0x0000796B
# define COLOR9 0x005E35B1
# define COLOR10 0x00F9A825


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
	int		in_path;
	t_link	*link;
	struct s_point point;
}				t_room;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	//controls
	int		zoom;
	int		x_zoom;
	int		y_zoom;
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


void	read_in_info(t_data *data, t_info *info, t_room **room_arr);
void	read_rooms(t_info *info, t_room **room_arr, char *line);
void	add_links(t_room **room_arr, char *line, int num_rooms);

t_room *add_room(t_info *info);
void	draw_graph(t_data *data);
int	controls(int key, t_data *data);
//hash-map
int	hash_map(char *name, t_info *info, t_room **room_arr);
int	hasher(char *name, int num_rooms);
int	lookup(char *name, int num_rooms, t_room **room_arr);


void	init_data(t_data *data);
void	init_info(t_info *info);
void	make_line(t_data *data, t_point a, t_point b);

void	rotate(t_point *a, t_data *data);

void	color_paths(t_room **room_arr, char *line, int num_rooms, int num_paths);
int color_paths_firstline(t_room **room_arr, char *line, int num_rooms);
void	free_data(t_data *data);
void	free_str_arr(char **arr);
void exit_error(t_data *data, char *message);
#endif