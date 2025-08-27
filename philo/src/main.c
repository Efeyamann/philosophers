#include "../includes/philosophers.h"

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
