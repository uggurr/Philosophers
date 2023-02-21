#include "philo.h"

int	main(int ag, char **av)
{
	t_struct	str;
	t_philo		*philo;

	philo = malloc(sizeof(t_philo) * str.number_of_philosophers);
	if (ag == 5 || ag == 6)
	{
		get_arg(av, ag, &str);
		identify_arg(philo, &str);
		identify_fork(philo, &str);
	}
	else
		return (0);
}
