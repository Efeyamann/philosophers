#ifndef UTILS_H
# define UTILS_H

int		check_args(int ac, char *av[]);
int		ft_atoi(const char *str);
void	free_philo_table(t_philo_table *table);
void	free_philo_info(t_thread *thread);

#endif