#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	ft_write(philo, "fork has a taken");
	pthread_mutex_lock(&philo->left_fork);
	ft_write(philo, "fork has a taken");
	philo->last_eat = now_time();
	philo->eat_count++;
	ft_write(philo, "is sleeping");
	ussleep(philo->str->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

int	is_it_dead(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->str->number_of_philosophers)
	{
		pthread_mutex_lock(&philo->str->eat);
		if (ft_diff(philo[i].last_eat) >= philo->str->time_to_die)
		{
			ft_write(&philo[i], "Is dead");
			dead_value(philo);
			pthread_mutex_unlock(&philo->str->eat);
			return (1);
		}
		pthread_mutex_unlock(&philo->str->eat);

	}
	return (0);
}

void	*routine(void *philo)
{
	while (1)
	{
		eating(philo);
	}
}

void	create_thread(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->str->number_of_philosophers)
		pthread_create(&philo[i].th_philo, NULL, routine, &philo[i]);
	while (1)
	{
		//dhfskf;
	}
}
