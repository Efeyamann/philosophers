#include "../../includes/philosophers.h"

void	free_philo_info(t_thread *thread)
{
	if (!thread)
		return ;
	pthread_mutex_destroy(&thread->lock);
	free(thread);
}

void	free_philo_table(t_philo_table *table)
{
	t_philo_table	*current;
	t_philo_table	*start;
	t_philo_table	*tmp;

	if (!table)
		return ;
	current = table;
	start = table;
	while (current->next && current->next != start)
		current = current->next;
	current->next = NULL;
	current = table;
	while (current)
	{
		tmp = current->next;
		pthread_mutex_destroy(&current->fork);
		free(current);
		current = tmp;
	}
}

void	shut_program(t_thread *info, t_philo_table **table)
{
	free_philo_table(*table);
	free(table);
	free_philo_info(info);
}
