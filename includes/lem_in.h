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

	int		num_ants;
	int		num_rooms;
	int		size;
	char	*start;
	char	*end;
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
#endif