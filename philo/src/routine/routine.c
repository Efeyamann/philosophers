#include "../../includes/philosophers.h"

void *routine(void *arg)
{
	t_philo_data	*data;
	t_philo_table	*philo;
	t_thread		*info;

	data = (t_philo_data *)arg;
	philo = data->philo;
	info = data->philo_info;
	while (!info->stop)
	{
		printf("%ld %d is thinking\n", timestamp_ms(), philo->philo_num);
		pthread_mutex_lock(&philo->fork);
		printf("%ld %d has taken a fork\n", timestamp_ms(), philo->philo_num);
		pthread_mutex_lock(&philo->next->fork);
		printf("%ld %d has taken a fork\n", timestamp_ms(), philo->philo_num);
		printf("%ld %d is eating\n", timestamp_ms(), philo->philo_num);
		gettimeofday(&philo->thinking_start, NULL);
		ft_usleep(info->eat_time);
		philo->total_meal++;
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
		printf("%ld %d is sleeping\n", timestamp_ms(), philo->philo_num);
		ft_usleep(info->sleep_time);
	}
	return (NULL);
}
