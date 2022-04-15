/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:46 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/15 15:53:10 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void set_start_end(int *start, int *end, t_info *info, char *line)
{
	char **all;

	if (*start || *end)
	{
		all = ft_strsplit(line, ' ');
		if (*start)
		{
			info->start = ft_strdup(all[0]);
			*start = FALSE;
		}
		else
		{
			info->end = ft_strdup(all[0]);
			*end = FALSE;
		}
		free_str_arr(all);
	}
}

static void	get_number_ants(t_info *info, char **line)
{
	//get number of ants //ADD ft_is_int()
	if (get_next_line(0, line))
	{
		if (info->num_ants < 0 && !ft_strchr(*line, (int)' '))
			info->num_ants = ft_atoi(*line);
		else
			info->num_ants = 0;
	}
	//else
		//return ERROR empty file
}

void	read_in_info(t_info *info)
{
	char	*line;
	int		start;
	int		end;

	start = FALSE;
	end = FALSE;

	get_number_ants(info, &line);
	free (line);
	while (get_next_line(0, &line) > 0)
	{
		//printf("HERE %s\n", line);
		if (!ft_strcmp("##start", line) || !ft_strcmp("##end", line))
		{
			if (!ft_strcmp("##start", line))
				start = TRUE;
			else
				end = TRUE;
			free (line);
			continue ;
		}
		if (line[0] == '#')
		{
			//get comment?
			free (line);
			continue ;
		}
		if (ft_strchr(line, (int)' '))//make better error checking
		{
			set_start_end(&start, &end, info, line);
			info->num_rooms++;
		
		}
		//if (ft_strchr(line, (int)'-'))//make better
		//{
		//	//add links
		//	free (line);
		//	break ;
		//}
		free (line);
	}
}
