#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
#include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct s_edge
{
	int				next_room_index; //can we directly include a pointer to the room?
	int				capacity; //not required if we only add rooms with capacity as neighbours
	struct s_edge	*reverse_edge; //can we add room as neighbour of reverse_edge based on next_room index and function add_neighbour(next_room_index, room_index)
	struct s_edge	*next_neighbor;

}				t_edge;

typedef struct s_room
{
	char			*name;
	t_room			*queue_next;
	t_room			*visited_next;
	t_room			*previous;
	struct s_edge	*neighbors;

}				t_room;

typedef struct s_solution
{
	t_room		*room;
	t_solution	*next_room;
}				t_solution;

typedef struct s_solutions
{
	t_solution	*solution;
	t_solutions	*next_solution;
}				t_solutions;

typedef struct s_path
{
	t_room	*room;
	t_path	*next_room;
}				t_path;

typedef struct s_paths
{
	t_path	*path;
	t_paths	*next_path;
}				t_paths;

typedef struct s_data
{
	int			num_ants;
	int			num_rooms;
	t_room		*queue;
	t_room		*visited;
	t_solutions	*solutions;
	t_paths		*paths;
}				t_data;

void	read_map(t_data *data);
void	solve(t_room *start);

#endif