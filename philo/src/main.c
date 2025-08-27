#include "../includes/philosophers.h"

static int	init_program(int ac, char **av,
	t_thread **philo_info, t_philo_table ***philo_table);
static int	run_simulation(t_thread *philo_info, t_philo_table **philo_table);

int	main(int ac, char *av[])
{
	t_thread		*philo_info;
	t_philo_table	**philo_table;

	if (init_program(ac, av, &philo_info, &philo_table))
		return (1);
	if (run_simulation(philo_info, philo_table))
		return (1);
	shut_program(philo_info, philo_table);
	return (0);
}

static int	init_program(int ac, char **av,
		t_thread **philo_info, t_philo_table ***philo_table)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (check(ac, av))
		return (1);
	*philo_info = malloc(sizeof(t_thread));
	if (!*philo_info)
		return (1);
	if (pthread_mutex_init(&(*philo_info)->lock, NULL) != 0)
		return (free(*philo_info), 1);
	fill_struct(*philo_info, ac, av);
	gettimeofday(&(*philo_info)->start, NULL);
	*philo_table = malloc(sizeof(t_philo_table *));
	if (!*philo_table)
	{
		free_philo_info(*philo_info);
		return (1);
	}
	(*philo_info)->return_val = fill_table(*philo_table, *philo_info);
	if (!(*philo_info)->return_val)
	{
		free(*philo_table);
		free_philo_info(*philo_info);
		return (1);
	}
	return (0);
}

static int	run_simulation(t_thread *philo_info, t_philo_table **philo_table)
{
	int				i;
	pthread_t		*threads;
	t_philo_data	*philo_data;
	t_philo_table	*curr;

	threads = malloc(sizeof(pthread_t) * philo_info->num_philo);
	philo_data = malloc(sizeof(t_philo_data) * philo_info->num_philo);
	if (!threads || !philo_data)
		return (shut_program(philo_info, philo_table), 1);
	i = 0;
	curr = *philo_table;
	while (i < philo_info->num_philo)
	{
		philo_data[i].philo = curr;
		philo_data[i].philo_info = philo_info;
		pthread_create(&threads[i], NULL, routine, &philo_data[i]);
		curr = curr->next;
		i++;
	}
	i = 0;
	while (i < philo_info->num_philo)
		pthread_join(threads[i++], NULL);
	free(threads);
	free(philo_data);
	return (0);
}
