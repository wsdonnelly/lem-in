/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:07:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/04 16:09:12 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	color_paths(t_room **room_arr, char *line, int num_rooms)
{
	char	**list;
	char	**info;
	int		i;
	int		idx;

	list = ft_strsplit(line, ' ');
	i = 0;
	while (list[i])
	{
		info = ft_strsplit(list[i], '-');
		idx = lookup(info[1], num_rooms, room_arr);
		(*room_arr)[idx].in_path = TRUE;
		free_str_arr(info);
		i++;
	}
	free_str_arr(list);
}
