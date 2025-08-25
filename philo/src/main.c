#include "../includes/philosophers.h"

int main(int ac, char *av[])
{
	t_thread	*philo_info;
	t_philo_table	**philo_table;

	if (ac < 5 || ac > 6)
		return (0);
	check(ac, av);
	if (check(ac, av))
		return (1);
	philo_info = (t_thread *)malloc(sizeof(t_thread));
	if(!philo_info)
		return 1;
	fill_struct(philo_info, ac, av);
	philo_table = (t_philo_table **)malloc(sizeof(t_philo_table *));
	if (!philo_table)
	{
		free_philo_info(philo_info);
		return (1);
	}
	free_philo_table(philo_table);
	free_philo_info(philo_info);
}