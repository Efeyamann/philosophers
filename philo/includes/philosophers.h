/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:48 by esir              #+#    #+#             */
/*   Updated: 2025/08/28 18:47:49 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo_table
{
	int						philo_num;
	long					meal_time;
	int						total_meal;
	int						is_eating;
	pthread_mutex_t			fork;
	struct s_philo_table	*next;
}							t_philo_table;

typedef struct s_thread
{
	pthread_mutex_t	lock;
	struct timeval	start;
	struct timeval	end;

	int				num_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				num_meal;
	int				stop;
	int				return_val;
}	t_thread;

typedef struct s_philo_data
{
	t_philo_table	*philo;
	t_thread		*philo_info;
}	t_philo_data;

int				check(int ac, char *av[]);
int				check_args(int ac, char *av[]);
int				ft_atoi(const char *str);
void			fill_struct(t_thread *philo_info, int ac, char *av[]);
int				fill_table(t_philo_table **table, t_thread *philo_info);
void			free_philo_table(t_philo_table *table);
void			free_philo_info(t_thread *thread);
t_philo_table	*new_node(void);
void			shut_program(t_thread *info, t_philo_table **table);
void			*routine(void *arg);
void			ft_usleep(long time_in_ms, t_thread *info);
void			*monitor_routine(void *arg);
long			get_time(t_thread *info);
int				run_simulation(t_thread *info, t_philo_table **table);
int				init_program(int ac, char **av, t_thread **philo_info,
					t_philo_table ***philo_table);
void			print_status(t_thread *info, int philo_num, char *status);
int				is_stopped(t_thread *info);

#endif