/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MBget_next_line.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:27 by mbeeler           #+#    #+#             */
/*   Updated: 2022/10/12 14:03:47 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 2560
# define FD_SIZE 4096

int		get_next_line(const int fd, char **line);

#endif
