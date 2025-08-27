#include "../../includes/philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philo_data	*data;
	t_philo_table	*current;
	long			curr_time;
	int				i;

	data = (t_philo_data *)arg;
	while (!data->philo_info->stop)
	{
		current = data->philo;
		i = 0;
		while (i < data->philo_info->num_philo)
		{
			curr_time = get_time(data->philo_info);
			if ((curr_time - current->meal_time) >= data->philo_info->death_time)
			{
				printf("%ld %d died\n", curr_time, current->philo_num);
				data->philo_info->stop = 1;
				return (NULL);
			}
			current = current->next;
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
