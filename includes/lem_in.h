/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:32:03 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/04 10:47:54 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

#include<stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct s_edge
{
	int				next_room_index;
	int				res_capacity;
	int				flow;
	int				is_backtrack;
	struct s_edge	*reverse_edge;
	struct s_edge	*next;

}				t_edge;

typedef struct s_room
{
	int must_backtrack;
	struct s_edge	*in_edge;
	struct s_edge	*out_edge;
	int		in_path;
	int		has_flow;
	int				visited;
	char			*name;
	int previous_idx;
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
	int			index;
	struct s_queue_node	*next;
}				t_queue_node;

typedef struct s_queue
{
	struct s_queue_node	*head;
	struct s_queue_node	*tail;
}				t_queue;

typedef struct s_path_set
{
	struct s_queue_node	*path;
	int									steps;
	int									ants_on_path;
	int									lines;
	struct s_path_set		*next_path;
}				t_path_set;

typedef struct s_path_group
{
	struct s_path_set		*paths;
	struct s_path_group	*next_path_group;
	//int									min_lines;
}								t_path_group;


//old stuff
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
	char			*start;
	char			*end;
	t_line			*store_input_head;
	t_line			*store_input_tail;
	int				end_index;
	int				start_index;
	//remove and fix this?
	t_room			**graph;
	t_node			*name_list;
	int				flow_path;
	int				shortest_path;
	
	struct s_queue_node *cur_path;
	struct s_path_set *path_set;
	struct s_path_group *path_group;

	//? 
	//int			required_moves;
	//int				num_paths;
	int				best_solution;
	struct s_paths	*all_paths;
	struct s_paths	*solution_paths;
}				t_data;

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

void	check_links(t_parse *parse, t_data *data, t_room **graph);
void	check_rooms(t_data *data, char *line);
//graph creation
void	add_to_graph(t_data *data, t_room *graph, char *line);
void	set_rooms(char **room, t_data *data, t_room *graph);

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

void	path_bfs(t_data *data, t_room *graph);
void	flow_bfs(t_data *data, t_room *graph);

void	free_path(t_path **path);
void	map_paths(t_paths *all_paths, t_path *shortest_path);

//new and tests
void print_graph_test(t_room *graph, t_data *data);

void create_path_set(t_data *data, t_queue_node *path_to_add, int count);
//void get_best_paths(t_data *data);
int change_capacity(t_data *data, t_room *graph, int save, int flow);
void put_ants_on_path(t_data *data, t_path_group *path_group);
void create_path_group(t_data *data);
void	solve(t_data *data, t_room *graph);
void init_visited(t_data *data, t_room *graph);
t_path_group *compare_paths(t_data *data);
#endif