/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:24:19 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/15 15:32:15 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_room *add_room(t_info *info)
{
	t_room *temp;
	//int		i;

	temp = malloc(sizeof(t_room) * info->num_rooms);
	//ERROR

	//while (i < info->num_rooms)
	//	temp[i++].name = NULL;
	return (temp);
}
