/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:30:57 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 20:04:22 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*new;
	int		i;

	i = 0;
	list = ft_create_elem(av[0]);
	if (!list)
		return (list);
	while (++i < ac)
	{
		new = ft_create_elem(av[i]);
		new->next = list;
		list = new;
	}
	return (list);
}
