#include "../includes/philosophers.h"

void	free_philo_info(t_thread *thread)
{
	if (!thread)
		return;
	pthread_mutex_destroy(&thread->lock);
	free(thread);
}

void	free_philo_table(t_philo_table *table)
{
	t_philo_table *tmp;

	while (table)
	{
		tmp = table->next;
		pthread_mutex_destroy(&table->fork);
		free(table);
		table = tmp;
	}
}