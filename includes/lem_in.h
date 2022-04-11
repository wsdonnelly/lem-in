#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
<<<<<<< HEAD
=======
# include "get_next_line.h"
#include <stdio.h>
>>>>>>> will

# define TRUE 1
# define FALSE 0


typedef struct s_room
{
	char	*name;
<<<<<<< HEAD
	//neighbors
=======
	int		start;
	int		end;
	int		x;
	int		y;
	//test
	int room_num;
>>>>>>> will


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