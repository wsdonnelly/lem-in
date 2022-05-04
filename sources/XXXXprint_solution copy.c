/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XXXXprint_solution copy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/04 16:54:16 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_room_name(t_data data, t_print *print, char *room_name)
{
	if (ft_strcmp(room_name, data.end))
	{
		print->name_len = ft_strlen(room_name) - 2;
		print->room_name = ft_strnew(print->name_len);
		ft_strncpy(print->room_name, room_name, print->name_len);
	}
	else
		print->room_name = ft_strdup(data.end);
}

static void	print_line(t_data data, t_print *print, char *room_name)
{
	print->ant_num = print->line_num * data.num_paths + print->path_num
		- print->room_num * data.num_paths;
	if (print->print_room % 2 == 0)
		print->room_num++;
	if (print->ant_num > 0 && print->ant_num <= data.num_ants)
	{
		if (print->start_of_line && print->print_room % 2 == 0)
			ft_printf(" ");
		if (print->print_room % 2 == 0)
		{
			get_room_name(data, print, room_name);
			ft_printf("L%d-%s", print->ant_num, print->room_name);
			ft_strdel(&print->room_name);
			print->start_of_line++;
		}
	}
	print->print_room++;
}

void	print_solution(t_data data)
{
	t_print	print;
	t_path	*tmp;
	t_paths	*tmp2;

	print.line_num = -1;
	while (++print.line_num < data.best_solution)
	{
		print.start_of_line = 0;
		print.path_num = 1;
		tmp2 = data.solution_paths;
		while (tmp2)
		{
			tmp = tmp2->path->next_room;
			print.print_room = 0;
			print.room_num = 0;
			while (tmp)
			{
				print_line(data, &print, tmp->room.name);
				tmp = tmp->next_room;
			}
			tmp2 = tmp2->next_path;
			print.path_num++;
		}
		ft_printf("\n");
	}
}

void	print_paths(t_data data)
{
	t_print	print;
	t_path	*tmp;
	t_paths	*tmp2;

	ft_printf("\nSolution Paths\n");
	tmp2 = data.solution_paths;
	while (tmp2)
	{
		ft_printf("%s", tmp2->path->room.name);
		tmp = tmp2->path->next_room;
		print.print_room = 0;
		while (tmp)
		{
			if (print.print_room++ % 2 == 0)
			{
				get_room_name(data, &print, tmp->room.name);
				ft_printf("-%s", print.room_name);
				ft_strdel(&print.room_name);
			}
			tmp = tmp->next_room;
		}
		tmp2 = tmp2->next_path;
		ft_printf("\n");
	}
	ft_printf("\n");
}
