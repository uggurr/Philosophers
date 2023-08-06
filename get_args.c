#include "philo.h"

void	identify_fork(t_philo *philo, t_struct *str)
{
	int	i;

	i = -1;
	str->fork = malloc(sizeof(pthread_mutex_t) * str->number_of_philosophers);
	while (++i < str->number_of_philosophers)
		pthread_mutex_init(&str->fork[i], NULL);
	i = 0;
	while (i < str->number_of_philosophers)
	{
		philo[i].left_fork = &str->fork[i];
		if (i == 0)
			philo[i].right_fork = &str->fork[str->number_of_philosophers - 1];
		else
			philo[i].right_fork = &str->fork[i - 1];
		i++;
	}
	pthread_mutex_init(&str->print, NULL);
	pthread_mutex_init(&str->dead, NULL);
	pthread_mutex_init(&str->eat, NULL);
}

t_philo	*identify_arg(t_struct *str)
{
	int	i;
	t_philo *philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * str->number_of_philosophers);
	while (i < str->number_of_philosophers)
	{
		philo[i].id = i;
		philo[i].eat_count = 0;
		philo[i].last_eat = str->start;
		philo[i].str = str;
		i++;
	}
	return (philo);
}

t_struct	*get_arg(char **av, int ag)
{
	t_struct *str;

	str = malloc(sizeof(t_struct));
	if (check(ag,av))
		exit (0);
	if (atoi_check(ag,av))
		exit (0);
	str->number_of_philosophers = ft_atoi(av[1]);
	if (str->number_of_philosophers == 0)
		exit (0);
	str->time_to_die = ft_atoi(av[2]);
	str->time_to_eat = ft_atoi(av[3]);
	str->time_to_sleep = ft_atoi(av[4]);
	str->is_dead = 0;
	if (ag == 6)
		str->must_eat = ft_atoi(av[5]);
	else
		str->must_eat = -1;
	return (str);
}
