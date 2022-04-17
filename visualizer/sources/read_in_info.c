/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:46 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/16 11:47:25 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

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
void	get_comment(t_info *info, char *line)
{
	char **list;

	list = ft_strsplit(line, ' ');
	if (!ft_strcmp(list[1], "num_rooms"))
		info->num_rooms = ft_atoi(list[2]);
	else if (!ft_strcmp(list[1], "start"))
		info->start = ft_strdup(list[2]);
	else if (!ft_strcmp(list[1], "end"))
		info->end = ft_strdup(list[2]);
	free_str_arr(list);
}

t_room *malloc_room_arr(t_info *info)
{
	t_room *temp;
	int		i;
	temp = malloc(sizeof(t_room) * info->num_rooms);
	//ERROR
	i = 0;
	while (i < info->num_rooms)
		temp[i++].name = NULL;
	return (temp);
}


void	read_in_info(t_info *info, t_room **room_arr)
{
	char	*line;
	int		start;
	int		end;
	int		flag = 0;
	int max_coordinate;
	//t_room *room_arr;

	start = FALSE;
	end = FALSE;
	max_coordinate = 0;
	get_number_ants(info, &line);
	free (line);
	
	while (get_next_line(0, &line) > 0)
	{
	
		if (!ft_strcmp("##start", line) || !ft_strcmp("##end", line))
		{
			free (line);
			continue ;
		}
		if (line[0] == '#')
		{
			
			get_comment(info, line);
			
			free (line);
			continue ;
		}
		if (info->end != NULL && !flag)
		{
			*room_arr = malloc_room_arr(info);
			printf("malloc array\n");
			flag = 1;
		}
		//printf("HERE\n");
		//printf("room_arr[7]->name: %s\n", (*room_arr)[7].name);
		if (ft_strchr(line, (int)' '))//make better error checking
		{
			//printf("room arr[1]-> %s\n", room_arr[1].name);
			read_rooms(info, room_arr, line, &max_coordinate);
			free(line);
			continue ;
		}
		//if (ft_strchr(line, (int)'-'))//make better
		//{
		//	//add links
		//	free (line);
		//	break ;
		//}
		free (line);
	}
	

	
	printf("MAx COOrdinate: %d\n", max_coordinate);
}
