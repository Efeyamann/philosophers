/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_time_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:05 by esir              #+#    #+#             */
/*   Updated: 2025/08/28 18:47:06 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

long	get_time(t_thread *info)
{
	struct timeval	current;
	long			start_ms;
	long			current_ms;

	gettimeofday(&current, NULL);
	start_ms = (info->start.tv_sec * 1000) + (info->start.tv_usec / 1000);
	current_ms = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (current_ms - start_ms);
}

void	ft_usleep(long time_in_ms, t_thread *info)
{
	long	start_time;

	start_time = get_time(info);
	while ((get_time(info) - start_time) < time_in_ms)
	{
		if (is_stopped(info))
			break ;
		usleep(500);
	}
}

void	print_status(t_thread *info, int philo_num, char *status)
{
	pthread_mutex_lock(&info->lock);
	if (!info->stop)
		printf("%ld %d %s\n", get_time(info), philo_num, status);
	pthread_mutex_unlock(&info->lock);
}
