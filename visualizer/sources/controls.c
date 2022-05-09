/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:40:34 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/09 15:03:40 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	move_zoom(int key, t_data *data)
{
	if (key == DOWNARROW)
		data->y_offset += 10;
	else if (key == UPARROW)
		data->y_offset -= 10;
	else if (key == LEFTARROW)
		data->x_offset -= 10;
	else if (key == RIGHTARROW)
		data->x_offset += 10;
	else if (key == EQUAL)
		data->zoom += 1;
	else if (key == MINUS)
		data->zoom -= 1;
	else if (key == X)
		data->x_zoom += 1;
	else if (key == Y)
		data->y_zoom += 1;
}

static void	basic_controls(t_data *data, int key)
{
	if (key == ESCAPE)
	{
		free_data(data);
		exit (0);
	}
}

static void	rotation(int key, t_data *data)
{
	if (key == KEYPAD8)
		data->alpha += .02;
	else if (key == KEYPAD5)
		data->alpha -= .02;
	else if (key == KEYPAD4)
		data->beta -= .02;
	else if (key == KEYPAD6)
		data->beta += .02;
	else if (key == KEYPAD7)
		data->gamma -= .02;
	else if (key == KEYPAD9)
		data->gamma += .02;
}

int	controls(int key, t_data *data)
{
	if (key == ESCAPE)
		basic_controls(data, key);
	else if ((key >= 0x7B && key <= 0x7E) || key == MINUS || key == EQUAL \
	|| key == X || key == Y)
		move_zoom(key, data);
	else if (key >= 0x56 && key <= 0x5C)
		rotation(key, data);
	mlx_clear_window(data->mlx, data->win);
	draw_graph(data);
	return (0);
}
/*
static void	basic_controls(int key, t_data *data)
{
	if (key == P)
		data->projection ^= 1;
	else if (key == SPACE)
		init_data(data);
	else if (key == ESCAPE)
	{
		free_map(data);
		exit (0);
	}
}

void	display_controls(t_data *data)
{
	mlx_string_put(data->mlx, data->win, \
	50, 910, 0xFFFFFF, "Controls");
	mlx_string_put(data->mlx, data->win, \
	50, 930, 0xFFFFFF, "arrow keys: move image");
	mlx_string_put(data->mlx, data->win, \
	50, 950, 0xFFFFFF, "+(=) and - : zoom");
	mlx_string_put(data->mlx, data->win, \
	50, 970, 0xFFFFFF, "q and w : change elevation");
	mlx_string_put(data->mlx, data->win, \
	50, 990, 0xFFFFFF, "numpad 456789: rotate");
	mlx_string_put(data->mlx, data->win, \
	50, 1010, 0xFFFFFF, "p: toggle projection (parallel/isometric");
	mlx_string_put(data->mlx, data->win, \
	50, 1030, 0xFFFFFF, "space: reset");
	mlx_string_put(data->mlx, data->win, \
	50, 1050, 0xFFFFFF, "esc: exit");
}

int	controls(int key, t_data *data)
{
	if (key == P || key == SPACE || key == ESCAPE)
		basic_controls(key, data);
	else if ((key >= 0x7B && key <= 0x7E) || key == MINUS || key == EQUAL \
			|| key == Q || key == W)
		move_zoom_elev(key, data);
	else if (key >= 0x56 && key <= 0x5C)
		rotation(key, data);
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}
*/