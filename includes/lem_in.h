/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:32:03 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/28 10:26:10 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdio.h>
# include <limits.h>
//#include <stdlib.h>

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
}				t_room;

typedef struct s_node
{
	char			*name;
	struct s_node	*next;
}				t_node;

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
	char			*store_input;
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

typedef struct s_print
{
	int		line_num;
	int		start_of_line;
	int		print_room;
	int		path_num;
	int		room_num;
	int		name_len;
	int		ant_num;
	char	*room_name;
}				t_print;

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

void	read_map(t_data *data, t_room **graph);
void	make_graph(int *flag, t_data *data, t_room **graph);
void	add_to_graph(t_data *data, char *line);
void	check_rooms(t_data *data, char *line);
//store_data
void	store_data(t_data *data, char *line);
void	print_data(t_data *data);
void print_comments(t_data *data);
//rooms
void	set_rooms(char **room, t_data *data);
void	both_start_end(char *start_room, char *end_room, t_data *data);
void	set_end_rooms(char *end_room, char *room_2, t_data *data);
void	set_start_rooms(char *start_room, char *room_2, t_data *data);
//util
void	free_str_arr(char **arr);
void	free_graph(t_room **graph, t_data *data);
void	free_edge_list(t_edge *head);
void	free_data(t_data *data);
int		exit_error(t_data *data, char *message);
int		is_valid_int(char *num);
//hash_map
int		hash_map(char *name, int num_rooms, t_room **graph);
//linked list
t_edge	*add_edge(t_data *data, int index1, int index2);
t_edge	*add_reverse_edge(t_data *data, int index1, int next, t_edge *forward);
void	solve(t_data data, t_room *graph, int argc);
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
void	print_paths(t_data data);

#endif