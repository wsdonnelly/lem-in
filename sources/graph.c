/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:33 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/15 12:13:59 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room *create_room_array(t_data *data)
{
	int	size = (data->num_rooms - 2) * 2 + 2;
	int	i;
	t_room *temp;
	
	printf("size: %d\n", size);
	temp = (t_room *)malloc(sizeof(t_room ) * size);
	//if (!graph)
		//exit ERROR
	i = 0;
	while (i < size) //init here
		temp[i++].name = NULL;
	return (temp);
}



/*
static int	hasher(char *room, int size, t_room *graph)
{

}
*/

void	create_graph(t_data *data, t_room **graph)
{
	char *line;
	char **links;

	*graph = create_room_array(data);

	//assuming robust error checking and line format "A-B"
	while (get_next_line(0, &line) > 0)
	{
		links = ft_strsplit(line, '-');

	

		//printf("line: %s\n", line);
		free_str_arr(links);
		free(line);
	}

}