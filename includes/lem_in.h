#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
#include <stdio.h>

# define TRUE 1
# define FALSE 0


typedef struct s_vertex
{
	char	*name;
	int		start;
	int		end;


}				t_vertex;

typedef struct s_data
{
	int	num_ants;
	int	num_rooms;
}				t_data;

void	read_map(t_data *data);

#endif