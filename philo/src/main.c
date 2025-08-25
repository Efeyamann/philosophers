#include "../includes/philosophers.h"

int main(int ac, char *av[])
{
	t_thread	*philo_info;
	t_philo_table	**philo_table;

	if (ac < 5 || ac > 6)
		return (0);
	check(ac, av);
	philo_info = (t_thread *)malloc(sizeof(t_thread));
	fill_struct(philo_info, ac, av);
}