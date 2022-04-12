#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
#include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct s_edge
{
	int				room_index;
	int				capacity;
	struct s_edge	*reverse_edge;
	struct s_edge	*next;

}				t_edge;

typedef struct s_room
{
	char			*name;
	struct s_edge	*neighbors;

}				t_room;

typedef struct s_data
{
	int	num_ants;
	int	num_rooms;
}				t_data;

void	read_map(t_data *data);

#endif