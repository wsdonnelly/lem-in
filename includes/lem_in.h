/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:32:03 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/12 11:39:20 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <limits.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct s_edge
{
	int				next_room_index;
	int				is_forward;
	int				flow;
	struct s_edge	*reverse_edge;
	struct s_edge	*next;

}				t_edge;

typedef struct s_room
{
	int				visited;
	int				in_path;
	char			*name;
	int				previous_idx;
	struct s_edge	*previous_edge;
	struct s_edge	*neighbors;
}				t_room;

typedef struct s_node
{
	char			*name;
	struct s_node	*next;
}				t_node;

typedef struct s_queue_node
{
	int					index;
	struct s_queue_node	*next;
}				t_queue_node;

typedef struct s_queue
{
	int	head;
	int	tail;
	int	*queue;
}			t_queue;

typedef struct s_path_set
{
	int					steps;
	int					ants_on_path;
	int					lines;
	int					line_start;
	int					*ant_nums;
	struct s_queue_node	*path;
	struct s_path_set	*next_path;
}				t_path_set;

typedef struct s_path_group
{
	struct s_path_set	*paths;
	struct s_path_group	*next_path_group;
}				t_path_group;

typedef struct s_data
{
	int					num_ants;
	int					num_rooms;
	int					size;
	char				*start;
	char				*end;
	int					end_index;
	int					start_index;
	int					flow_path;
	int					shortest_path;
	int					verbose;
	struct s_queue_node	*cur_path;
	struct s_path_group	*path_group;
	struct s_line		*store_input_head;
	struct s_line		*store_input_tail;
	struct s_room		**graph;
	struct s_node		*name_list;
}				t_data;

typedef struct s_name
{
	char	*one_in;
	char	*one_out;
	char	*two_in;
	char	*two_out;
	int		index_1in;
	int		index_1out;
	int		index_2in;
	int		index_2out;
	int		index_end;
	int		index_start;
}				t_name;

typedef struct s_parse
{
	char	*line;
	int		flag;
	int		room_check;
}				t_parse;

typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}				t_line;

typedef struct s_paths
{
	struct s_path_group	*tmp_group;
	struct s_path_set	*path_set;
	struct s_path_set	*tmp_path;
	struct s_queue_node	*room;
	struct s_queue_node	*tmp_room;
}				t_paths;

//parser
void					read_map(t_data *data, t_room **graph);
void					check_links(t_parse *parse, t_data *data, \
							t_room **graph);
void					check_rooms(t_data *data, char *line);
//graph creation
void					add_to_graph(t_data *data, char *line);
void					set_rooms(char **room, t_data *data);
void					both_start_end(char *start_room, char *end_room, \
							t_data *data);
void					set_end_rooms(char *end_room, char *room_2, \
							t_data *data);
void					set_start_rooms(char *start_room, char *room_2, \
							t_data *data);
t_edge				*add_edge(t_data *data, int index1, int index2);
t_edge				*add_reverse_edge(t_data *data, int index1, \
							int next, t_edge *forward);
//store_data
void					store_data(t_data *data, char *line);
void					print_data(t_data *data);
//free functions
void					free_paths(t_path_group *path_group);
void					free_str_arr(char **arr);
void					free_graph(t_room **graph, t_data *data);
void					free_data(t_data *data);
void					free_result(t_path_group *path_group);
//additional functions
int						hash_map(char *name, int num_rooms, t_room **graph);
int						exit_error(t_data *data, char *message);
int						is_valid_int(char *num);
//BFS
void					bfs(t_data *data, t_room *graph, int path);
void					enqueue(t_queue *queue, int index);
int						dequeue(t_queue *queue);
void					init_visited(t_data *data, t_room *graph);
int						*create_queue(t_data *data, t_queue *queue);
//solve
void					solve(t_data *data, t_room *graph);
void					create_path_group(t_data *data);
void					create_path_set(t_data *data, \
							t_queue_node *path_to_add, int steps);
int						change_capacity(t_data *data, \
							t_room *graph, int save, int flow);
void					put_ants_on_path(t_data *data, \
							t_path_group *path_group);
t_path_group	*compare_paths(t_data *data);
//print results and verbose
void					print_verbose(t_data *data, t_path_group *group, \
							t_room *graph);
void					init_ant_nums(t_path_group *group);
void					print_result(t_path_group *group, t_room *graph, \
							t_data *data);
//test stuff to remove in master
void					print_graph_test(t_room *graph, t_data *data);
void					print_ants(t_path_group *best);

#endif