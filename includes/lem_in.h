#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

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
	struct s_edge	*neighbors;
}				t_room;

typedef struct s_node
{
	char *name;
	struct s_node *next;
}				t_node;

typedef struct s_data
{
	int		num_ants;
	int		num_rooms;
	int		size;
	char	*start;
	char	*end;
	int		end_index;
	int		start_index;
	//t_room	**graph;
	t_node	*name_list;
}				t_data;

typedef struct s_name
{
	char *one_in;
	char *one_out;
	char *two_in;
	char *two_out;
	int index_1in;
	int index_1out;
	int index_2in;
	int index_2out;
	int index_end;
	int index_start;
}				t_name;

void	read_map(t_data *data, t_room **graph);
t_room	*malloc_graph(t_data *data);
void	create_graph(t_data *data, t_room **graph, char *line);
//util
void	free_str_arr(char **arr);
void	free_graph(t_room **graph, t_data *data);
void	free_edge_list(t_edge *head);
void	free_data(t_data *data);
int	exit_error(t_room **graph, t_data *data, char *message);
int	is_valid_int(char *num);
//hash_map
int	hash_map(char *name, int num_rooms, t_room **graph);
//linked list
t_edge	*add_edge(t_room **graph, t_data *data, int index1, int index2);
//t_edge	*add_reverse_edge(t_edge **head, int next, t_edge *forward);
t_edge	*add_reverse_edge(t_room **graph, t_data *data, int index1,  int next, t_edge *forward);
#endif