/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:29:32 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 20:04:14 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*end;

	end = *begin_list;
	if (end)
	{
		while (end->next)
			end = end->next;
		end->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
