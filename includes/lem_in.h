#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
#include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct s_edge
{
	int				next_room_index;
	int				capacity;
	struct s_edge	*reverse_edge;
	struct s_edge	*next;

}				t_edge;

typedef struct s_room
{
	char			*name;
	char			*previous;
	struct s_edge	*neighbors;
	int				start;
	int				end;
}				t_room;

typedef struct s_path
{
	struct s_room	room;
	struct s_path	*next_room;
}				t_path;

typedef struct s_paths
{
	struct s_path	*path;
	struct s_paths	*next_path;
}				t_paths;

typedef struct s_data
{

	int				num_ants;
	int				num_rooms;
	int				size;
	char			*start;
	char			*end;
	int				end_index;
	int				start_index;
	int				augmented_path;
	int				best_solution;
	int				required_moves;
	int				num_paths;
	struct s_path	*queue;
	struct s_path	*visited;
	struct s_path	*shortest_path;
	struct s_edge	*neighbor;
	struct s_paths	*all_paths;
	struct s_paths	*solution_paths;
}				t_data;

void	read_map(t_data *data, t_room **graph);
t_room	*malloc_graph(t_data *data);
void	create_graph(t_data *data, t_room **graph, char *line);
//util
void	free_str_arr(char **arr);
//hash_map
int	hash_map(char *name, int num_rooms, t_room **graph);
//linked list
t_edge	*add_edge(t_edge **head, int next);
t_edge	*add_reverse_edge(t_edge **head, int next, t_edge *forward);
void	solve(t_data data, t_room *graph);
void	find_shortest_path(t_data *data, t_room *graph);
void	add_room_to_path(t_room room, t_path **path);
void	free_path(t_path **path);
void	find_fewest_moves(t_data *data, t_room *graph);
void	build_shortest_path(t_path **path, t_room *graph);
void	add_shortest_path_to_all_paths(t_paths **all_paths, t_path *shortest_path);
void	free_paths(t_paths **paths);
void	copy_all_paths_to_solution(t_paths **solution_paths, t_paths *all_paths);
void	map_paths(t_paths *all_paths, t_path *shortest_path);
t_path	*create_room_on_path(t_room room);
void	print_solution(t_data data);
#endif