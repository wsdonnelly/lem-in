/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:07:34 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/24 15:24:02 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_graph(t_room **graph, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if ((*graph)[i].name)
			free((*graph)[i].name);
		free_edge_list((*graph)[i].neighbors);
		i++;
	}
	if (*graph)
		free (*graph);
}

void	free_name_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free (temp->name);
		free (temp);
	}
}

void free_store_data(t_line *store_input_head)
{
	t_line *temp;
	t_line *cpy;

	temp = store_input_head;
	while (temp)
	{
		cpy = temp;
		free(cpy->line);
		free(cpy);
		temp = temp->next;
	}
}

void	free_data(t_data *data)
{
	if (data->start)
		free(data->start);
	if (data->end)
		free(data->end);
	if (data->name_list)
		free_name_list(data->name_list);
	if (data->store_input_head)
		free_store_data(data->store_input_head);
}

int	exit_error(t_data *data, char *message)
{
	free_graph(data->graph, data);
	free_data(data);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit (EXIT_FAILURE);
}

int	is_valid_int(char *num)
{
	int		i;
	long	val;

	i = 0;
	val = 0;
	if (num[i] == '-')
		return (0);
	if (num[i] == '+')
		i++;
	while (num[i])
	{
		if (ft_isdigit(num[i]))
			val = (val * 10) + num[i] - '0';
		else
			return (0);
		i++;
	}
	if (val > INT_MAX)
		return (0);
	return (1);
}
