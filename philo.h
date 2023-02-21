#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_struct
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*fork;
}	t_struct;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_t		th_philo;
	t_struct		*str;
}	t_philo;

int		ft_atoi(const char *nptr);
void	get_arg(char **av, int ag, t_struct *str);
void	identify_arg(t_philo *philo, t_struct *str);
void	identify_fork(t_philo *philo, t_struct *str);
#endif
