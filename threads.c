#include "philo.h"

long long int	now_time(void)
{
	//gettimeofday();
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(&philo->left_fork);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	*routine(void *philo)
{
	while (1)
	{
		eating(philo);
		write();
	}
}

void	create_thread(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->str->number_of_philosophers)
		pthread_create(philo[i].th_philo, NULL, routine, &philo[i]);
}
