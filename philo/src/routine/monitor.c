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

void	*monitor_routine(void *arg)
{
	t_philo_data	*data;
	t_philo_table	*current;
	long			curr_time;
	int				i;

	data = (t_philo_data *)arg;
	while (!is_stopped(data->philo_info))
	{
		current = data->philo;
		i = 0;
		while (i < data->philo_info->num_philo)
		{
			pthread_mutex_lock(&data->philo_info->lock);
			curr_time = get_time(data->philo_info);
			if (!current->is_eating && (curr_time - current->meal_time) >= data->philo_info->death_time)
			{
				printf("%ld %d died\n", curr_time, current->philo_num);
				data->philo_info->stop = 1;
				pthread_mutex_unlock(&data->philo_info->lock);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philo_info->lock);
			current = current->next;
			i++;
		}
		if (check_meals(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
