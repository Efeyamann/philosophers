/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:48:11 by esir              #+#    #+#             */
/*   Updated: 2025/08/28 18:48:12 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	fill_table(t_philo_table **table, t_thread *philo_info)
{
	int				i;
	t_philo_table	*head;
	t_philo_table	*current;

	head = new_node();
	if (!head)
		return (0);
	*table = head;
	current = head;
	i = 1;
	while (i < philo_info->num_philo)
	{
		current->philo_num = i;
		current->next = new_node();
		if (!current->next)
			return (0);
		current = current->next;
		i++;
	}
	current->philo_num = i;
	current->next = head;
	return (1);
}
