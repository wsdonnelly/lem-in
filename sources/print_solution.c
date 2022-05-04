/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/04 16:46:03 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	count_steps(t_paths *tmp2, int best_solution)
{
	int		i;
	t_path	*tmp;

	while (tmp2)
	{
		i = 0;
		tmp = tmp2->path;
		while (tmp)
		{
			tmp = tmp->next_room;
			i++;
		}
		tmp2->steps = best_solution - i / 2 + 1;
		tmp2->new_ant = 0;
		tmp2 = tmp2->next_path;
	}
}

static t_ant	*create_ant(int i)
{
	t_ant	*ant;

	ant = (t_ant *)malloc(sizeof(t_ant));
	if (!ant)
		return (NULL);
	ant->num = i;
	ant->path = NULL;
	ant->next_ant = NULL;
	return (ant);
}

static t_ant	*create_ant_structure(int num_ants)
{
	t_ant	*ant;
	t_ant	*tmp;
	int		i;

	i = 0;
	ant = create_ant(1);
	tmp = ant;
	while (++i < num_ants)
	{
		tmp->next_ant = create_ant(i + 1);
		tmp = tmp->next_ant;
	}
	return (ant);
}

void	print_solution(t_data data)
{
	t_ant	*ant;
	t_ant	*tmp;
	int		i;

	count_steps(data.solution_paths, data.best_solution);
	ant = create_ant_structure(data.num_ants);
	i = -1;
	while (++i < data.best_solution)
		print_line(data, ant, i);
	while (ant)
	{
		tmp = ant;
		ant = ant->next_ant;
		free(tmp);
	}
}
