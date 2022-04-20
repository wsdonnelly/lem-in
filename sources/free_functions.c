/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/19 22:51:12 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_path(t_path **path)
{
	t_path	*tmp1;
	t_path	*tmp2;

	tmp1 = *path;
	while (tmp1)
	{	
		tmp2 = tmp1;
		tmp1 = tmp1->next_room;
		free(tmp2);
	}
}

void	free_paths(t_paths **paths)
{
	t_paths	*tmp1;
	t_paths	*tmp2;

	tmp1 = *paths;
	while (tmp1)
	{
		tmp2 = tmp1;
		free_path(&tmp1->path);
		tmp1 = tmp1->next_path;
		free(tmp2);
	}
}
