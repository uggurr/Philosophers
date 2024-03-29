#include "philo.h"

long long int	now_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long int	ft_diff(long long int i)
{
	return (now_time() - i);
}

void	ussleep(int y)
{
	unsigned long	i;

	i = now_time();
	while ((int)ft_diff(i) <= y)
		usleep(100);
}
