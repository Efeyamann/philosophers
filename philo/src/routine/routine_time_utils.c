#include "../../includes/philosophers.h"

long	timestamp_ms(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

long	get_time(t_thread *info)
{
	struct timeval	current;
	long			start_ms;
	long			current_ms;

	gettimeofday(&current, NULL);
	start_ms = (info->start.tv_sec * 1000) + (info->start.tv_usec / 1000);
	current_ms = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (current_ms - start_ms);
}

void	ft_usleep(long ms)
{
	long	start;

	start = timestamp_ms();
	while ((timestamp_ms() - start) < ms)
		usleep(100);
}
