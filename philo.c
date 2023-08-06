#include "philo.h"

void	finish_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->str->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo->str->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->str->dead);
	pthread_mutex_destroy(&philo->str->eat);
	pthread_mutex_destroy(&philo->str->print);
	free(philo->str->fork);
	free(philo->str);
	free(philo);
}

int	main(int ag, char **av)
{
	t_struct	*str;
	t_philo		*philo;
	int i = -1;

	//philo = malloc(sizeof(t_philo) * str->number_of_philosophers);
	if (ag == 5 || ag == 6)
	{
		str = get_arg(av, ag);
		str->start = now_time();
		philo = identify_arg(str);
		identify_fork(philo, str);
		create_thread(philo);
		while (++i < str->number_of_philosophers)
			pthread_join(philo[i].th_philo, NULL);
		finish_process(philo);
	}
	else
		return (0);
}
