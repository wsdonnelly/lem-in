/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/21 11:29:19 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_line(t_data data, t_print *print, char *room_name)
{
	print->ant_num = print->line_num * data.num_paths + print->path_num
		- print->room_num * data.num_paths;
	if (print->print_room % 2 == 0)
		print->room_num++;
	if (print->ant_num > 0 && print->ant_num <= data.num_ants)
	{
		if (print->start_of_line && print->print_room % 2 == 0)
			printf(" "); //change to ft_printf   
		if (print->print_room % 2 == 0)
		{
			if (ft_strcmp(room_name, data.end))
			{
				print->name_len = ft_strlen(room_name) - 2;
				print->room_name = ft_strnew(print->name_len);
				ft_strncpy(print->room_name, room_name, print->name_len);
			}
			else
				print->room_name = ft_strdup(data.end);
			printf("L%d-%s", print->ant_num, print->room_name); //change to ft_printf   
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
		printf("\n"); //change to ft_printf    
	}
}

void	print_paths(t_data data)
{
	t_print	print;
	t_path	*tmp;
	t_paths	*tmp2;

	printf("\nPaths"); //change to ft_printf   
	tmp2 = data.solution_paths;
	while (tmp2)
	{
		tmp = tmp2->path;
		while (tmp)
		{
			printf("%s ", tmp->room.name); //change to ft_printf    
			tmp = tmp->next_room;
		}
		tmp2 = tmp2->next_path;
		printf("\n"); //change to ft_printf    
	}
	printf("\n"); //change to ft_printf   
}
