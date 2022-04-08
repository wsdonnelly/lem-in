#include "lem_in.h"

void	read_map(t_data *data)
{
	char	*line;
	int		start;
	int		end;

	start = 0;
	end = 0;
	
	while (get_next_line(0, &line) > 0)
	{
		//line 1 #of ants //what if empty?
		//printf("line: %s\n", line);
		if (data->num_ants < 0)
			data->num_ants = ft_atoi(line);
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
		//get room
		//do untill links
		if (ft_strchr(line, (int)' '))
		{
			data->num_rooms++;
		}
		//get links
		
		free (line);
	}
}
