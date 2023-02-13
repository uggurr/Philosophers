#include "philo.h"

void    *ft_thread_begin(void *philo)
{
    //deneme
}

void    ft_thread_creat(t_philo *philo)
{
    int i;

    i = -1;
    while (++i < philo->list->number_of_philosophers)
        philo[i].th_philo = pthread_create(&philo[i].th_philo, NULL, ft_thread_begin, &philo[i]);    //hata sonrası..
    while (1)
        usleep(1000); //ölme fonksiyonnu
}

void    ft_fork_assign(t_philo *philo, t_list *list)
{
    int i;

    i = -1;
    list->fork = malloc(sizeof(pthread_mutex_t) * list->number_of_philosophers);
    while (++i < list->number_of_philosophers)
    {
        philo[i].right_fork = &list->fork[i];
        if (i == 0)
            philo[i].left_fork = &list->fork[list->number_of_philosophers - 1];
        else
            philo[i].left_fork = &list->fork[i - 1];
    }
}

void    ft_philo_assign(t_philo *philo, t_list *list)
{
    int i;

    i = -1;
    philo = malloc(sizeof(t_philo) * philo->list->number_of_philosophers);
    while (++i < philo->list->number_of_philosophers)
    {
        philo[i].id = i;
        philo[i].eat_count = 0;
        philo[i].list = &list;
    }
}

void    ft_check_argv(char **str, t_list *list, int argc)
{
    list->number_of_philosophers = ft_atoi(str[1]);
    list->time_to_dead = ft_atoi(str[2]);
    list->must_eat = ft_atoi(str[3]);
    list->time_to_sleep = ft_atoi(str[4]);
    if (argc == 6)
        list->must_eat = ft_atoi(str[5]);
    else
        list->must_eat = 0;
}

int main(int argc, char **argv)
{
    t_list  list;
    t_philo philo;

    if (argc == 5 || argc == 6)
    {
        ft_check_argv(argv, &list, argc);
        ft_philo_assign(&philo, &list);
        ft_fork_assign(&philo, &list);
        ft_thread_creat(&philo);
    }
    /*else
        printf("error\n");*/
    return (0);
}