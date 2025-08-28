/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:48:21 by esir              #+#    #+#             */
/*   Updated: 2025/08/28 18:48:22 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	is_stopped(t_thread *info)
{
	int	ret;

	pthread_mutex_lock(&info->lock);
	ret = info->stop;
	pthread_mutex_unlock(&info->lock);
	return (ret);
}

static int	check_meals(t_philo_data *data)
{
	int				i;
	int				finished_philos;
	t_philo_table	*current;

	if (data->philo_info->num_meal == -1)
		return (0);
	finished_philos = 0;
	i = 0;
	current = data->philo;
	pthread_mutex_lock(&data->philo_info->lock);
	while (i < data->philo_info->num_philo)
	{
		if (current->total_meal >= data->philo_info->num_meal)
			finished_philos++;
		current = current->next;
		i++;
	}
	if (finished_philos == data->philo_info->num_philo)
	{
		data->philo_info->stop = 1;
		pthread_mutex_unlock(&data->philo_info->lock);
		return (1);
	}
	pthread_mutex_unlock(&data->philo_info->lock);
	return (0);
}

static int	check_death(t_philo_table *philo, t_philo_data *data)
{
	long	curr_time;

	pthread_mutex_lock(&data->philo_info->lock);
	curr_time = get_time(data->philo_info);
	if (!philo->is_eating && (curr_time - philo->meal_time)
		>= data->philo_info->death_time)
	{
		printf("%ld %d died\n", curr_time, philo->philo_num);
		data->philo_info->stop = 1;
		pthread_mutex_unlock(&data->philo_info->lock);
		return (1);
	}
	pthread_mutex_unlock(&data->philo_info->lock);
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo_data	*data;
	t_philo_table	*current;
	int				i;

	data = (t_philo_data *)arg;
	while (!is_stopped(data->philo_info))
	{
		current = data->philo;
		i = 0;
		while (i < data->philo_info->num_philo)
		{
			if (check_death(current, data))
				return (NULL);
			current = current->next;
			i++;
		}
		if (check_meals(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
