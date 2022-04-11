#include "lem_in.h"

static void	init_data(t_data *data)
{
	data->num_ants = -1;
	data->num_rooms = 0;
}

int main()
{
	t_data	data;

	init_data(&data);
	read_map(&data);

	printf("num ants: %d\n", data.num_ants);
	printf("num rooms: %d\n", data.num_rooms);
	return (0);
}