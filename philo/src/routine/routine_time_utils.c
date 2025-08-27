#include "../../includes/philosophers.h"

long	timestamp_ms(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

void ft_usleep(long ms)
{
	long	start;

	start = timestamp_ms();
	while((timestamp_ms() - start) < ms)
		usleep(100);
}