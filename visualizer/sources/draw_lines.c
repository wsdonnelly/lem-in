/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:37:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/29 14:32:29 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

/*
** Bresenham's algo 2
*/

static void	draw_line(t_data *data, t_line *line, t_point *a, t_point *b)
{
	while (1)
	{
		//mlx_pixel_put(data->mlx, data->win, a->x + data->x_offset, \
		//a->y + data->y_offset, data->color);
		mlx_pixel_put(data->mlx, data->win, a->x, \
		a->y, data->color);
		if (a->x == b->x && a->y == b->y)
			break ;
		line->e2 = line->err;
		if (line->e2 > -line->dx)
		{
			line->err -= line->dy;
			a->x += line->sx;
		}
		if (line->e2 < line->dy)
		{
			line->err += line->dx;
			a->y += line->sy;
		}
	}
}

/*
** Bresenham's algo 1
*/

void	make_line(t_data *data, t_point a, t_point b)
{
	t_line	line;

	line.dx = ft_abs(b.x - a.x);
	line.dy = ft_abs(b.y - a.y);
	if (a.x < b.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (a.y < b.y)
		line.sy = 1;
	else
		line.sy = -1;
	if (line.dx > line.dy)
		line.err = line.dx / 2;
	else
		line.err = -line.dy / 2;
	draw_line(data, &line, &a, &b);
}
