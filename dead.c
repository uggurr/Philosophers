#include "philo.h"

void	dead_value(t_philo *philo)
{
	pthread_mutex_lock(&philo->str->dead);
	philo->str->is_dead = 1;
	pthread_mutex_unlock(&philo->str->dead);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->str->dead);
	if (philo->str->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->str->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->str->dead);
	return (0);
}
