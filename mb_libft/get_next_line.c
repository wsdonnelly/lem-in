/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeeler <mbeeler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/01/10 09:23:40 by mbeeler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_line(char **line, char **str)
{
	*str = ft_strchr(*line, '\n');
	if (*str)
	{
		**str = '\0';
		*str += 1;
		if (**str == '\0')
			*str = NULL;
		else
			*str = ft_strdup(*str);
		return (1);
	}
	return (0);
}

static int	ft_iterate_line(char **line, char *buf, char **str)
{
	char	*tmp;

	if (!*line)
		*line = ft_strdup(buf);
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_strdel(&tmp);
	}
	if (!*line)
		return (-1);
	return (ft_check_line(line, str));
}

int	get_next_line(const int fd, char **line)
{
	int					ret;
	char				buf[BUFF_SIZE + 1];
	static char			*str[FD_SIZE];

	if (read(fd, buf, 0) == -1 || fd < 0 || fd > FD_SIZE - 1 || line == NULL)
		return (-1);
	*line = str[fd];
	if (str[fd] && ft_check_line(line, &str[fd]))
		return (1);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		ret = ft_iterate_line(line, buf, &str[fd]);
		if (ret != 0)
			return (ret);
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (*line)
		return (1);
	return (0);
}
