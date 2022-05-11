/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:35:45 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/11 13:52:55 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

typedef struct s_info
{
	int		num_rooms;
	FILE	*fp;
	int		end;
	int		num;
	int		density;
}				t_info;

static void	set_rooms(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_rooms)
	{
		if (i == info->end)
			fprintf(info->fp, "##end\n");
		fprintf(info->fp, "%d %d %d\n", i, \
		rand() % info->num_rooms, rand() % info->num_rooms);
		i++;
	}
}

static void	set_links_large(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->num_rooms)
	{
		j = 0;
		info->num = rand() % info->num_rooms;
		if (info->num != i)
			fprintf(info->fp, "%d-%d\n", i, info->num);
			j++;
		i++;
	}
}

static void	set_links_small(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->num_rooms)
	{
		info->density = rand() % info->num_rooms;
		j = 0;
		while (j < info->density % 6)
		{
			info->num = rand() % info->num_rooms;
			if (info->num != i)
				fprintf(info->fp, "%d-%d\n", i, info->num);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
	{
		printf("usage: ./a.out <num_rooms>\n");
		return (0);
	}
	info.num_rooms = atoi(av[1]);
	srand(time(0));
	info.end = rand() % info.num_rooms;
	info.fp = fopen("rando_map", "w+");
	fprintf(info.fp, "%d\n", rand() % 100 + 1);
	fprintf(info.fp, "##start\n");
	set_rooms(&info);
	if (info.num_rooms >= 1000)
		set_links_large(&info);
	else
		set_links_small(&info);
	fclose(info.fp);
	return (0);
}
