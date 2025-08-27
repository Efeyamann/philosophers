#include "../../includes/philosophers.h"

static void	take_forks(t_philo_table *philo, t_thread *info)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		printf("%ld %d has taken a fork\n", get_time(info), philo->philo_num);
		pthread_mutex_lock(&philo->next->fork);
		printf("%ld %d has taken a fork\n", get_time(info), philo->philo_num);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		printf("%ld %d has taken a fork\n", get_time(info), philo->philo_num);
		pthread_mutex_lock(&philo->fork);
		printf("%ld %d has taken a fork\n", get_time(info), philo->philo_num);
	}
}

static void	eat(t_philo_table *philo, t_thread *info)
{
	printf("%ld %d is eating\n", get_time(info), philo->philo_num);
	philo->meal_time = get_time(info);
	ft_usleep(info->eat_time);
	philo->total_meal++;
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
	take_forks(philo, info);
	eat(philo, info);
	release_forks(philo);
	printf("%ld %d is sleeping\n", get_time(info), philo->philo_num);
	ft_usleep(info->sleep_time);
}

void	*routine(void *arg)
{
	t_philo_data	*data;
	t_philo_table	*philo;
	t_thread		*info;

	data = (t_philo_data *)arg;
	philo = data->philo;
	info = data->philo_info;
	philo->meal_time = get_time(info);
	while (!info->stop)
	{
		printf("%ld %d is thinking\n", get_time(info), philo->philo_num);
		philo_cycle(philo, info);
	}
	return (NULL);
}
