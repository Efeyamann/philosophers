/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:48:30 by esir              #+#    #+#             */
/*   Updated: 2025/08/28 18:48:31 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	take_forks(t_philo_table *philo, t_thread *info)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		print_status(info, philo->philo_num, "has taken a fork");
		pthread_mutex_lock(&philo->next->fork);
		print_status(info, philo->philo_num, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		print_status(info, philo->philo_num, "has taken a fork");
		pthread_mutex_lock(&philo->fork);
		print_status(info, philo->philo_num, "has taken a fork");
	}
}

static void	eat(t_philo_table *philo, t_thread *info)
{
	pthread_mutex_lock(&info->lock);
	philo->is_eating = 1;
	philo->meal_time = get_time(info);
	philo->total_meal++;
	pthread_mutex_unlock(&info->lock);
	print_status(info, philo->philo_num, "is eating");
	ft_usleep(info->eat_time, info);
	pthread_mutex_lock(&info->lock);
	philo->is_eating = 0;
	pthread_mutex_unlock(&info->lock);
}

static void	release_forks(t_philo_table *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

static void	philo_cycle(t_philo_table *philo, t_thread *info)
{
	print_status(info, philo->philo_num, "is thinking");
	take_forks(philo, info);
	eat(philo, info);
	release_forks(philo);
	print_status(info, philo->philo_num, "is sleeping");
	ft_usleep(info->sleep_time, info);
}

void	*routine(void *arg)
{
	t_philo_data	*data;
	t_philo_table	*philo;
	t_thread		*info;

	data = (t_philo_data *)arg;
	philo = data->philo;
	info = data->philo_info;
	pthread_mutex_lock(&info->lock);
	philo->meal_time = get_time(info);
	pthread_mutex_unlock(&info->lock);
	if (info->num_philo == 1)
	{
		print_status(info, philo->philo_num, "has taken a fork");
		ft_usleep(info->death_time, info);
		return (NULL);
	}
	if (philo->philo_num % 2 == 0)
		ft_usleep(info->eat_time / 2, info);
	while (!is_stopped(info))
	{
		philo_cycle(philo, info);
		if (info->num_philo % 2 != 0)
			ft_usleep(info->eat_time / 2, info);
	}
	return (NULL);
}
