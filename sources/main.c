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
	read_map(&data);


	create_graph(&data, &graph);
	//solve();
	//out_put();
	printf("HERE-> %s\n", graph[0].name);
	printf("num ants: %d\n", data.num_ants);
	printf("num rooms: %d\n", data.num_rooms);
	printf("start room: %s\n", data.start);
	printf("end room: %s\n", data.end);
	//free_data()
	//free_graph()
	return (0);
}