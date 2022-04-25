/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:03:34 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/23 15:33:30 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	rotate_x(t_point *point, t_data *data)
{
	int	y;

	y = point->y;
	point->y = (int)(y * cos(data->alpha) + point->z * sin(data->alpha));
	point->z = (int)(-y * sin(data->alpha) + point->z * cos(data->alpha));
}

static void	rotate_y(t_point *point, t_data *data)
{
	int	x;

	x = point->x;
	point->x = (int)(x * cos(data->beta) + point->z * sin(data->beta));
	point->z = (int)(-x * sin(data->beta) + point->z * cos(data->beta));
}

static void	rotate_z(t_point *point, t_data *data)
{
	int	x;
	int	y;

	x = point->x;
	y = point->y;
	point->x = (int)(x * cos(data->gamma) - y * sin(data->gamma));
	point->y = (int)(x * sin(data->gamma) + y * cos(data->gamma));
}

void	rotate(t_point *a, t_data *data)
{
	rotate_x(a, data);
	rotate_y(a, data);
	rotate_z(a, data);
	//rotate_x(b, data);
	//rotate_y(b, data);
	//rotate_z(b, data);
}
