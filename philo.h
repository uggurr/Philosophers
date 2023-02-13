#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_list
{
    int             number_of_philosophers;
    int             time_to_dead;
    int             time_to_eat;
    int             time_to_sleep;
    int             must_eat;
    pthread_mutex_t *fork;
}   t_list;

typedef struct s_philo
{
    int             id;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;        
    int             eat_count;
    pthread_t       th_philo;
    t_list          *list;
}   t_philo;

int	ft_atoi(const char *nptr);

#endif