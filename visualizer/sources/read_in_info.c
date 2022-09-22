/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:46 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/22 13:43:29 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include <stdio.h>

/*
* set random z coordinate here
*/

static t_room	*malloc_room_arr(t_info *info)
{
	t_room	*temp;
	int		i;

	temp = malloc(sizeof(t_room) * info->num_rooms);
	if (!temp)
		exit(0);
	i = 0;
	while (i < info->num_rooms)
	{
		temp[i].name = NULL;
		temp[i].link = NULL;
		temp[i].z = rand() % 23;
		temp[i].in_path = -1;
		i++;
	}
	return (temp);
}

static void	init_parse(t_parse *parse)
{
	parse->flag = 0;
	parse->flag2 = 0;
	parse->start = FALSE;
	parse->end = FALSE;
}

static void	make_room_arr(t_info *info, t_room **room_arr, t_parse *parse)
{
	if (info->end != NULL && !parse->flag)
	{
		*room_arr = malloc_room_arr(info);
		parse->flag = 1;
	}
}

static int	parse_input(t_info *info, t_room **room_arr, t_parse *parse)
{
	if (parse->line[0] == '#')
	{
		get_comment(info, parse->line);
		return (1);
	}
	make_room_arr(info, room_arr, parse);
	
	if (ft_strchr(parse->line, (int) ' ') && !ft_strchr(parse->line, (int) 'L'))
	{
		printf("read room\n");
		read_rooms(info, room_arr, parse->line);
		return (1);
	}
	else if (ft_strchr(parse->line, (int) '-') && !ft_strchr(parse->line, (int) 'L'))
	{
		printf("add link\n");
		add_links(room_arr, parse->line, info->num_rooms);
		return (1);
	}
	else if (ft_strchr(parse->line, (int) 'L'))
	{
		printf("L HERE\n");
		add_paths(info, room_arr, parse);
		free (parse->line);
		return (1);
	}
	else 
	{
		printf("HERE DEAD END\n");
	}
		
	return (0);
}

void	read_in_info(t_info *info, t_room **room_arr)
{
	t_parse	parse;
	int ret;
	
	init_parse(&parse);
	get_first_line(info, &parse.line);
	printf("line: %s\n", parse.line);
	while ((ret = get_next_line(0, &parse.line)))
	{
		//printf("line: %s line[0]: %d\n", parse.line, (int)parse.line[0]);
		printf("line: %s | ret: %d\n", parse.line, ret);
		if (!ft_strcmp(parse.line, "Solution Paths"))
			exit(0);
		if (parse_input(info, room_arr, &parse))
			continue ;
		free (parse.line);
	}
	while (( get_next_line(0, &parse.line) > -1))
	{
		printf("l word\n");
	}
}
