#include "../includes/philosophers.h"

static int	init_philo_info(int ac, char **av, t_thread **philo_info)
{
	*philo_info = malloc(sizeof(t_thread));
	if (!*philo_info)
		return (1);
	if (pthread_mutex_init(&(*philo_info)->lock, NULL) != 0)
		return (free(*philo_info), 1);
	fill_struct(*philo_info, ac, av);
	gettimeofday(&(*philo_info)->start, NULL);
	return (0);
}

static int	init_philo_table(t_thread *philo_info, t_philo_table ***philo_table)
{
	*philo_table = malloc(sizeof(t_philo_table *));
	if (!*philo_table)
		return (1);
	philo_info->return_val = fill_table(*philo_table, philo_info);
	if (!philo_info->return_val)
	{
		free(*philo_table);
		return (1);
	}
	return (0);
}

int	init_program(int ac, char **av,
	t_thread **philo_info, t_philo_table ***philo_table)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (check(ac, av))
		return (1);
	if (init_philo_info(ac, av, philo_info))
		return (1);
	if (init_philo_table(*philo_info, philo_table))
	{
		free_philo_info(*philo_info);
		return (1);
	}
	return (0);
}
