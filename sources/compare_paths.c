/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:53:40 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/06 13:30:08 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path_group	*compare_paths(t_data *data)
{
	t_path_group	*tmp;
	t_path_group	*best;
	int				count;

	count = INT_MAX;
	tmp = data->path_group;
	while (tmp)
	{
		put_ants_on_path(data, tmp);
		if (tmp->paths->lines < count)
		{
			count = tmp->paths->lines;
			best = tmp;
		}
		tmp = tmp->next_path_group;
	}
	printf("BEST---> %d\n", count);
	return (best);
}
