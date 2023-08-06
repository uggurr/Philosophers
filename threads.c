#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_write(philo, "fork has a taken");
	if (philo->str->number_of_philosophers == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		ussleep(philo->str->time_to_die);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	ft_write(philo, "fork has a taken");
	pthread_mutex_lock(&philo->str->eat);
	philo->last_eat = now_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->str->eat);
	ft_write(philo, "Is eating");
	ussleep(philo->str->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	is_it_dead(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->str->number_of_philosophers)
	{
		pthread_mutex_lock(&philo->str->eat);
		if ((int)(ft_diff(philo[i].last_eat)) >= philo->str->time_to_die)
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

int	are_they_eat(t_philo *philo)
{
	int	i;

	if (philo->str->must_eat == -1)
		return (0);
	i = -1;
	pthread_mutex_lock(&philo->str->eat);
	while (++i < philo->str->number_of_philosophers)
	{
		if (philo[i].eat_count < philo->str->must_eat)
		{
			pthread_mutex_unlock(&philo->str->eat);
			return (0);
		}
	}
	pthread_mutex_unlock(&philo->str->eat);
	dead_value(philo);
	return (1);
}

int	all_cases(t_philo *philo)
{
	if (is_it_dead(philo) == 1 || are_they_eat(philo) == 1)
		return (1);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*s_philo;

	s_philo = philo;
	if (s_philo->id % 2 == 0)
		usleep(10000);
	while (is_dead(s_philo) == 0)
	{
		eating(s_philo);
		ft_write(s_philo, "Is sleaping");
		ussleep(s_philo->str->time_to_sleep);
		ft_write(s_philo, "Is thinking");
	}
	return (NULL);
}

void	create_thread(t_philo *philo)
{
	int	i;
	int	x;

	i = -1;
	while (++i < philo->str->number_of_philosophers)
		pthread_create(&philo[i].th_philo, NULL, routine, &philo[i]);
	//getchar();
	while (1)
	{
		x = all_cases(philo);
		if (x == 1)
			break ;
	}
}
