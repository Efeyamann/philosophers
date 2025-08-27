#include "../includes/philosophers.h"

static int	create_threads(t_thread *info,
	t_philo_table **table, pthread_t *threads, t_philo_data *data)
{
	int				i;
	t_philo_table	*curr;

	curr = *table;
	i = 0;
	while (i < info->num_philo)
	{
		data[i].philo = curr;
		data[i].philo_info = info;
		if (pthread_create(&threads[i], NULL, routine, &data[i]) != 0)
			return (1);
		curr = curr->next;
		i++;
	}
	return (0);
}

static void	join_threads(t_thread *info, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
		pthread_join(threads[i++], NULL);
}

int	run_simulation(t_thread *info, t_philo_table **table)
{
	pthread_t		*threads;
	pthread_t		monitor_thread;
	t_philo_data	*data;

	threads = malloc(sizeof(pthread_t) * info->num_philo);
	data = malloc(sizeof(t_philo_data) * info->num_philo);
	if (!threads || !data)
		return (shut_program(info, table), 1);
	if (create_threads(info, table, threads, data))
		return (free(threads), free(data), 1);
	pthread_create(&monitor_thread, NULL, monitor_routine, &data[0]);
	pthread_join(monitor_thread, NULL);
	info->stop = 1;
	join_threads(info, threads);
	free(threads);
	free(data);
	return (0);
}
