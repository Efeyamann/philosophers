/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:48:07 by esir              #+#    #+#             */
/*   Updated: 2025/08/28 18:48:08 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

t_philo_table	*new_node(void)
{
	t_philo_table	*node;

	node = malloc(sizeof(t_philo_table));
	if (!node)
		return (NULL);
	pthread_mutex_init(&node->fork, NULL);
	node->philo_num = 0;
	node->meal_time = 0;
	node->total_meal = 0;
	node->is_eating = 0;
	node->next = NULL;
	return (node);
}
