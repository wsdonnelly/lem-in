#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
#include <stdio.h>

# define TRUE 1
# define FALSE 0


typedef struct s_room
{
	char	*name;
	int		start;
	int		end;
	int capacity;
	//test
	int room_num;


}				t_room;

typedef struct s_data
{
	int	num_ants;
	int	num_rooms;
}				t_data;

void	read_map(t_data *data);
//void	add_room(t_room **room_arr, int num_rooms, char *line);
void	add_room(t_room **room_arr, int num_rooms);

#endif