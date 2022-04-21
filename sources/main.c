#include "lem_in.h"

static void	init_data(t_data *data)
{
	data->num_ants = -1;
	data->num_rooms = 0;
	data->size = -1;
	data->start = NULL;
	data->end = NULL;
	data->name_list = NULL;
}

int main()
{
	t_data	data;
	t_room	*graph;

	graph = NULL;
	//data.graph = &graph;
	init_data(&data);
	read_map(&data, &graph);
	ft_printf("%B", "a big hello from ftprintf");
	//freename_list
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
	printf("index end: %d\n", data.end_index);
	printf("index start: %d\n", data.start_index);
	
	
	free_graph(&graph, &data);
	free_data(&data);
	return (0);
}