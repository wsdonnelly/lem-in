/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:41:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/11 12:35:00 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 32
# define MAX_FD 4096

typedef struct s_list
{
	char			*ln;
	int				fd;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int	get_next_line(const int fd, char **line);

#endif
