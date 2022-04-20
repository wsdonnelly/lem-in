/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/20 23:17:32 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_solution(t_data data)
{
	t_path	*tmp;
	t_paths	*tmp2;
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		len;
	int		ant_num;
	char	*room_name;

	i = -1;
	while (++i < data.best_solution)
	{
		j = 0;
		l = 1;
		tmp2 = data.solution_paths;
		while (tmp2)
		{
			tmp = tmp2->path->next_room;
			k = 0;
			m = 0;
			while (tmp)
			{
				ant_num = i * data.num_paths + l - m * data.num_paths;
				if (k % 2 == 0)
					m++;
				if (ant_num > 0 && ant_num <= data.num_ants)
				{
					if (j && k % 2 == 0)
						printf(" "); //change to ft_printf   
					if (k % 2 == 0)
					{
						if (ft_strcmp(tmp->room.name, data.end))
						{
							len = ft_strlen(tmp->room.name) - 2;
							room_name = ft_strnew(len);
							ft_strncpy(room_name, tmp->room.name, len);
						}
						else
							room_name = ft_strdup(data.end);
						printf("L%d-%s", ant_num, room_name); //change to ft_printf   
						ft_strdel(&room_name);
						j++;
					}
				}
				tmp = tmp->next_room;
				k++;
			}
			tmp2 = tmp2->next_path;
			l++;
		}
		printf("\n"); //change to ft_printf    
	}
}
