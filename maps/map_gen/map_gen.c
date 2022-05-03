/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:35:45 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/03 21:41:23 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>


int main(int ac, char **av)
{
	int num_rooms;
	int i;
	FILE *fp;
	int end;
	int num;

	if (ac != 2)
	{
		printf("usage: ./a.out <num_rooms>\n");
		return (0);
	}
	num_rooms = atoi(av[1]);
	srand(time(0));
	end = rand() % num_rooms;
	fp = fopen("rando_map", "w+");
	fprintf(fp, "%d\n", rand() % 100 + 1);
	fprintf(fp, "##start\n");
	i = 0;
	while (i < num_rooms)
	{
		if (i == end)
			fprintf(fp, "##end\n");
		fprintf(fp, "%d %d %d\n", i, rand() % num_rooms, rand() % num_rooms);
		i++;
	}
	i = 0;
	while (i < num_rooms)
	{	
		num = rand() % num_rooms;
		if (num != i)
			fprintf(fp, "%d-%d\n", i, num);
		i++;
	}
	fclose(fp);
	return (0);
}