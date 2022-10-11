/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:41:48 by akilk             #+#    #+#             */
/*   Updated: 2022/10/11 10:52:00 by wdonnell         ###   ########.fr       */
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

int	init_ant_nums(t_path_group *group)
{
	t_path_set	*tmp;
	int			i;
	int			paths;

	tmp = group->paths;
	paths = 0;
	while(tmp)
	{
		tmp->ant_nums = (int *)malloc(sizeof (int) * tmp->ants_on_path);
		i = 0;
		while (i < tmp->ants_on_path)
		{
			tmp->ant_nums[i] = -1;
			i++;
		}
		paths++;
		tmp = tmp->next_path;
	}
	return (paths);
}

void	set_ant_nums(t_path_set *set, t_data *data)
{
	int			ant;
	int			i;
	t_path_set	*start;

	ant = 1;
	start = set;
	i = 0;
	while(ant <= data->num_ants)
	{
		set = start;
		while (set && (i < set->ants_on_path))
		{
			set->ant_nums[i] = ant;
			set = set->next_path;
			ant++;
		}
		i++;
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

void	print_result(t_path_group *group, t_room *graph, t_data *data)
{
	int			line;
	int			ant;
	int			fst_ant;
	t_path_set	*set;
	
	set_ant_nums(group->paths, data);
	line = 1;
	while (line <= group->paths->lines)
	{
		set = group->paths;
		while (set)
		{
			ant = 0;
			while (ant < set->ants_on_path)
			{
				fst_ant = set->ant_nums[ant];
				print_ant(set, graph, line - ant, fst_ant);
				ant++;
			}
			set = set->next_path;
		}
		ft_printf("\n");
		line++;
	}
	if (data->verbose)
	{
		ft_printf("\n");
		print_verbose(data, group, graph);
	}
}
