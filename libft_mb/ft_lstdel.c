/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:48:10 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/17 13:36:24 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_element;

	if (*del)
	{
		while (*alst)
		{
			next_element = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next_element;
		}
	}
}
