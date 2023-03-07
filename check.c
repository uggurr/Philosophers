#include "philo.h"

int	atoi_check(int ag, char **av)
{
	int		i;
	long	tmp;

	i = 0;
	while (++i < ag)
	{

		tmp = ft_atoi(av[i]);
		printf("%ld\n",tmp);
		if (tmp > 2147483647 || tmp < -2147483648)
        {
            printf("merhaba");
			return (1);
        }
	}
	return (0);
}

int     check(int ag, char **av)
{
    int	i;
	int	j;

	i = 0;
	while (++i < ag)
	{
		j = -1;
		while (av[i][++j])
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
		if (!av[i][0])
			return (1);
	}
	return (0);
}