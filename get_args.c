#include "philo.h"

void	identify_fork(t_philo *philo, t_struct *str)
{
	int	i;

	i = 0;
	str->fork = malloc(sizeof(pthread_mutex_t) * str->number_of_philosophers);
	while (i < str->number_of_philosophers)
	{
		philo[i].left_fork = str->fork[i];
		if (i == 0)
		{
			philo[i].right_fork = str->fork[str->number_of_philosophers - 1];
		}
		else
			philo[i].right_fork = str->fork[i - 1];
		i++;
	}
	i = 0;
	while (i < str->number_of_philosophers)
	{
		pthread_mutex_init(&philo[i].left_fork, NULL);
		pthread_mutex_init(&philo[i].right_fork, NULL);
		i++;
	}
	pthread_mutex_init(&str->print, NULL);
	pthread_mutex_init(&str->dead, NULL);
	pthread_mutex_init(&str->eat, NULL);
}

void	identify_arg(t_philo *philo, t_struct *str)
{
	int	i;

	i = 0;
	while (i < str->number_of_philosophers)
	{
		philo[i].id = i;
		philo[i].eat_count = 0;
		philo[i].str = str;
		i++;
	}
}

void	get_arg(char **av, int ag, t_struct *str)
{
	str->number_of_philosophers = ft_atoi(av[1]);
	str->time_to_die = ft_atoi(av[2]);
	str->time_to_eat = ft_atoi(av[3]);
	str->time_to_sleep = ft_atoi(av[4]);
	if (ag == 6)
		str->must_eat = ft_atoi(av[5]);
	else
		str->must_eat = 0;
}
