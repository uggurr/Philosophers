#include "philo.h"

void	ft_write(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->str->print);
	if (is_dead(philo) == 0)
		printf("%lldms %d %s\n", ft_diff(philo->str->start), philo->id + 1, str);
	pthread_mutex_unlock(&philo->str->print);
}
