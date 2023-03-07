#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "sys/time.h"

typedef struct s_struct
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	dead;
	long long int	start;
}	t_struct;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long long int	last_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		th_philo;
	t_struct		*str;
}	t_philo;

long				ft_atoi(char *nptr);
void			get_arg(char **av, int ag, t_struct *str);
void			identify_arg(t_philo *philo, t_struct *str);
void			identify_fork(t_philo *philo, t_struct *str);
void			dead_value(t_philo *philo);
int				is_dead(t_philo *philo);
void			ft_write(t_philo *philo, char *str);
void			ussleep(int y);
long long int	now_time(void);
long long int	ft_diff(long long int i);
void			create_thread(t_philo *philo);
int     		check(int ag, char **av);
int				atoi_check(int ag, char **av);
#endif
