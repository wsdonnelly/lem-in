/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/01 15:50:25 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	get_room_name(t_data data, t_ant *ant, char *room_name)
{
	if (ft_strcmp(room_name, data.end))
	{
		ant->name_len = ft_strlen(room_name) - 2;
		ant->room_name = ft_strnew(ant->name_len);
		ft_strncpy(ant->room_name, room_name, ant->name_len);
	}
	else
		ant->room_name = ft_strdup(data.end);
}

static void	send_new_ant(t_data data, t_ant *tmp1, int *j)
{
	t_paths	*tmp2;

	tmp2 = data.solution_paths;
	while (tmp2 && tmp2->new_ant)
		tmp2 = tmp2->next_path;
	if (tmp2)
	{
		tmp1->path = tmp2->path->next_room;
		get_room_name(data, tmp1, tmp1->path->room.name);
		if (*j)
			ft_putchar(' ');
		ft_printf("L%d-%s", tmp1->num, tmp1->room_name);
		ft_strdel(&tmp1->room_name);
		tmp2->new_ant = 1;
		*j = *j + 1;
	}
}

static void	move_ant(t_data data, t_ant *tmp1, int *j)
{
	if (tmp1->path->next_room)
	{
		if (*j)
			ft_putchar(' ');
		tmp1->path = tmp1->path->next_room->next_room;
		get_room_name(data, tmp1, tmp1->path->room.name);
		ft_printf("L%d-%s", tmp1->num, tmp1->room_name);
		ft_strdel(&tmp1->room_name);
		*j = *j + 1;
	}
}

void	print_line(t_data data, t_ant *ant, int i)
{
	t_paths	*tmp2;
	t_ant	*tmp1;
	int		j;

	j = 0;
	tmp2 = data.solution_paths;
	while (tmp2)
	{
		if (tmp2->steps > i)
			tmp2->new_ant = 0;
		tmp2 = tmp2->next_path;
	}
	tmp1 = ant;
	while (tmp1)
	{
		if (!tmp1->path)
			send_new_ant(data, tmp1, &j);
		else
			move_ant(data, tmp1, &j);
		tmp1 = tmp1->next_ant;
	}
	ft_printf("\n");
}
