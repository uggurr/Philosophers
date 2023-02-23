#include "philo.h"

void	ft_write(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->str->print);
	printf("%lld %d %s\n", ft_diff(philo->str->start), philo->id, str);
	pthread_mutex_unlock(&philo->str->print);
}
