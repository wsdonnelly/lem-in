/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:41:48 by akilk             #+#    #+#             */
/*   Updated: 2022/10/08 11:38:07 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* -v verbose mode  */
void	print_verbose(t_data *data, t_path_group *group, t_room *graph)
{
	t_queue_node	*path;
	t_path_set		*set;

	ft_printf("PATHS USED:\n");
	set = group->paths;
	while(set)
	{
		path = set->path;
		ft_printf("%s->", data->start);
		while (path)
		{
			ft_printf("%s", graph[path->index].name);
			if(path->next)
				ft_printf("->");
			path = path->next;
		}
		ft_printf("\n");
		set = set->next_path;
	}
}

void	set_fst_ant(t_path_group *group)
{
	t_path_set *tmp;

	tmp = group->paths;
	while(tmp)
	{
		if (tmp->next_path)
			tmp->next_path->fst_ant_num = tmp->fst_ant_num + tmp->ants_on_path;
		tmp = tmp->next_path;
	}
}

void	print_ant(t_path_set *set, t_room *graph, int line, int ant)
{
	t_queue_node	*path;
	int	count;

	path = set->path;
	count = 1;
	if (line < 1 || line > set->steps)
		return ;
	while (path)
	{
		if (line == count)
			ft_printf("L%d-%s ", ant, graph[path->index].name);
		path = path->next;
		count++;
	}
}

void	print_result(t_path_group *group, t_room *graph)
{
	int			line;
	int			ant;
	int			fst_ant;
	t_path_set	*set;

	line = 1;
	while (line <= group->paths->lines)
	{
		set = group->paths;
		while (set)
		{
			fst_ant = 1 + set->fst_ant_num;
			ant = 0;
			while (ant < set->ants_on_path)
			{
				print_ant(set, graph, line - ant, ant + fst_ant);
				ant++;
			}
			set = set->next_path;
		}
		ft_printf("\n");
		line++;
	}
}
