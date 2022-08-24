/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/08/22 18:19:38 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_room_name(t_data *data, t_print *print, char *room_name)
{
	if (ft_strcmp(room_name, data->end))
	{
		print->name_len = ft_strlen(room_name) - 2;
		print->room_name = ft_strnew(print->name_len);
		ft_strncpy(print->room_name, room_name, print->name_len);
	}
	else
		print->room_name = ft_strdup(data->end);
}

/*
** All paths which were identified in the optimal solution are printed out
** room-by-room. Also the number of required moves in the optimal solution is
** printed to the standard output.
*/

void	print_paths(t_data *data)
{
	t_print	print;
	t_path	*tmp;
	t_paths	*tmp2;

	ft_printf("\nSolution Paths\n");
	tmp2 = data->solution_paths;
	while (tmp2)
	{
		ft_printf("%s", tmp2->path->room->name);
		tmp = tmp2->path->next_room;
		print.print_room = 0;
		while (tmp)
		{
			if (print.print_room++ % 2 == 0)
			{
				get_room_name(data, &print, tmp->room->name);
				ft_printf("-%s", print.room_name);
				ft_strdel(&print.room_name);
			}
			tmp = tmp->next_room;
		}
		tmp2 = tmp2->next_path;
		ft_printf("\n\n");
	}
	ft_printf("\nNumber of lines:\n%d\n\n", data->best_solution);
}
