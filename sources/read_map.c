#include "lem_in.h"

void	read_map(t_data *data)
{
	char	*line;
	int		start;
	int		end;

	//t_room	*room_arr;
	//t_room	temp;

	//room_arr = &temp;
	start = 0;
	end = 0;
	//get number of ants //ADD ft_is_int()
	if (get_next_line(0, &line))
	{
		if (data->num_ants < 0 && !ft_strchr(line, (int)' '))
			data->num_ants = ft_atoi(line);
		else
			data->num_ants = 0;
	}
	//else
		//return ERROR empty file
	while (get_next_line(0, &line) > 0)
	{
		//line 1 #of ants //what if empty?
		//printf("line: %s\n", line);
		
		if (!ft_strcmp("##start", line))
		{
			start = 1;
			free (line);
			continue ;
		}
		else if (!ft_strcmp("##end", line))
		{
			end = 1;
			free (line);
			continue ;
		}
		if (line[0] == '#')
		{
			//get comment?
			free (line);
			continue ;
		}
		//do untill links
		if (ft_strchr(line, (int)' '))
		{
			//get room
			
			data->num_rooms++;
			//add_room(&room_arr, data->num_rooms);
		}
		//get links
		
		free (line);
	}
}

