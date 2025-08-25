#ifndef PHILOSPHERS_H
# define PHILOSOPHERS_H

# include "utils.h"
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>

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

typedef struct s_philo_table
{
	int						philo_num;
	int						meal_time;
	int						total_meal;
	struct timeval			thinking_start;
	struct timeval			thinking_end;
	pthread_mutex_t			fork;
	struct s_philo_table	*next;
}	t_philo_table;

#endif