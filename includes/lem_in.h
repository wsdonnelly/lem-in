/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:32:03 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/17 19:10:08 by wdonnell         ###   ########.fr       */
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
	int				capacity;
	struct s_edge	*reverse_edge;
	struct s_edge	*next;

}				t_edge;

typedef struct s_room
{
	int				visited;
	char			*name;
	char			*previous;
	struct s_edge	*neighbors;
}				t_room;

typedef struct s_node
{
	char			*name;
	struct s_node	*next;
}				t_node;

typedef struct s_queue_node
{
	int			index;
	//get rid of this
	char *name;
	struct s_queue_node	*next;
}				t_queue_node;

typedef struct s_queue
{
	struct s_queue_node	*head;
	struct s_queue_node	*tail;
}				t_queue;

typedef struct s_path
{
	int						index;
	struct s_room	*room;
	struct s_path	*next_room;
}				t_path;

typedef struct s_paths
{
	struct s_path	*path;
	int				steps;
	int				new_ant;
	struct s_paths	*next_path;
}				t_paths;

typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}				t_line;

typedef struct s_data
{
	int				num_ants;
	int				num_rooms;
	int				size;
	char			*start;
	char			*end;
	t_line			*store_input_head;
	t_line			*store_input_tail;
	int				end_index;
	int				start_index;
	t_room			**graph;
	t_node			*name_list;
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

typedef struct s_ant
{
	int				num;
	struct s_path	*path;
	int				name_len;
	char			*room_name;
	struct s_ant	*next_ant;
}				t_ant;

typedef struct s_print
{
	int		print_room;
	char	*room_name;
	int		name_len;
}				t_print;

typedef struct s_parse
{
	char	*line;
	int		flag;
	int		room_check;
}				t_parse;

//parser
void	read_map(t_data *data, t_room **graph);
//void	get_start_end(t_data *data, char *line);
void	check_links(t_parse *parse, t_data *data, t_room **graph);
void	check_rooms(t_data *data, char *line);
//graph creation
void	add_to_graph(t_data *data, char *line);
void	set_rooms(char **room, t_data *data);
void	both_start_end(char *start_room, char *end_room, t_data *data);
void	set_end_rooms(char *end_room, char *room_2, t_data *data);
void	set_start_rooms(char *start_room, char *room_2, t_data *data);
//store_data
void	store_data(t_data *data, char *line);
void	print_data(t_data *data);
void	print_comments(t_data *data);
//util and additional functions
void	free_str_arr(char **arr);
void	free_graph(t_room **graph, t_data *data);
void	free_edge_list(t_edge *head);
void	free_data(t_data *data);
int		exit_error(t_data *data, char *message);
int		is_valid_int(char *num);
void	free_paths(t_paths **paths);
void	print_solution(t_data *data);
void	print_paths(t_data *data);
void	print_line(t_data *data, t_ant *ant, int i);
int		hash_map(char *name, int num_rooms, t_room **graph);
//linked list
t_edge	*add_edge(t_data *data, int index1, int index2);
t_edge	*add_reverse_edge(t_data *data, int index1, int next, t_edge *forward);
//solver
void	solve(t_data data, t_room *graph, int argc);
void	find_shortest_path(t_data *data, t_room *graph);
void	find_fewest_moves(t_data *data, t_room *graph);
void	change_capacity(t_path *path, t_room *graph, t_data *data);
//path
void	add_room_to_path(t_room *room, t_path **path);
void	add_shortest_path_to_all_paths(t_paths **all_paths, \
t_path *shortest_path);
t_path	*create_room_on_path(t_room *room);
void	build_shortest_path(t_path **path, t_room *graph);
void	copy_all_paths_to_solution(t_paths **solution_paths, \
t_paths *all_paths);
void	free_path(t_path **path);
void	map_paths(t_paths *all_paths, t_path *shortest_path);

#endif