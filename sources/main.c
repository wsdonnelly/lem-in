#include "lem_in.h"

static void	init_data(t_data *data)
{
	data->num_ants = -1;
	data->num_rooms = 0;
}

int main()
{
	t_data	data;
	t_room	*graph;

	init_data(&data);
	read_map(&data, &graph);
	//solve();
	//out_put();
	//printf("HERE-> %s\n", graph[1].name);
	/*
	printf("num ants: %d\n", data.num_ants);
	printf("num rooms: %d\n", data.num_rooms);
	printf("start room: %s\n", data.start);
	printf("end room: %s\n", data.end);
	*/
	t_edge *temp;
	int i = 0;
	while (i < data.size)
	{
		printf("graph[%d].name: %s\n", i, graph[i].name);
		//printf("graph[%d].start: %d\n", i, graph[i].start);
		//printf("graph[%d].end: %d\n", i, graph[i].end);
		
		temp = graph[i].neighbors;
		while(temp)
		{
			printf("neighbor: %s\n", graph[temp->next_room_index].name);
			printf("capacity: %d\n\n", temp->capacity);
			temp = temp->next;
		}
		printf("\n");
		i++;
	}
	
	//free_data()
	//free_graph()
	return (0);
}