#include "../includes/philosophers.h"

void fill_structs(t_thread *philo_info, int ac, char *av[])
{
	philo_info->num_philo = ft_atoi(av[1]);
	philo_info->death_time = ft_atoi(av[2]);
	philo_info->eat_time = ft_atoi(av[3]);
	philo_info->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		philo_info->num_meal = ft_atoi(av[5]);
	else
		philo_info->num_meal = -1;
	philo_info->stop = 0;
	philo_info->return_val = 1;
}