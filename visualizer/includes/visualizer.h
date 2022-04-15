/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:19:07 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/15 21:18:12 by wdonnell         ###   ########.fr       */
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
#include <stdio.h>
# include <fcntl.h>

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

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
	int		z;
	int		link;
}				t_room;


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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}				t_line;

void	read_in_info(t_info *info);
void	read_rooms(t_info *info, t_room *room_arr, char *line, int *max_coordiante);
void	free_str_arr(char **arr);
t_room *add_room(t_info *info);

#endif