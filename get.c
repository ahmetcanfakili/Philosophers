/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:11 by afakili           #+#    #+#             */
/*   Updated: 2022/09/04 04:21:07 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void get_arguments(int argc, char **argv, t_data *data)
{
    data = malloc(sizeof(t_data));
    if (!data)
    {
        printf("Malloc Error! (data)");
        exit(1);
    }
    data->number_of_forks = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		data->must_eat = 0;
	else
		data->must_eat = ft_atoi(argv[5]);
        printf("%d %d %d %d %d", data->number_of_forks, data->time_to_die, 
            data->time_to_eat, data->time_to_sleep, data->must_eat);
}

void get_forks(t_data *data)
{
    int i;

    i = 0;
    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_forks);
    if (!data->forks)
    {
        printf("Malloc Error! (data->forks)");
        free(data->forks);        
        exit(1);
    }
    while (i++ < data->number_of_forks)
        pthread_mutex_init(&data->forks[i], 0);
}

void *func(void *arg)
{
    void *tmp;
    tmp = arg;
    printf("Thread Test: %p\n", tmp);
    return (0);
}

void get_threads(t_data *data)
{
    int i;
    
    data->philos = malloc(sizeof(t_philo) * data->number_of_forks);
    if (!data->philos)
    {
        printf("Malloc Error! (data->philos)");
        free(data->philos);
        exit(1);
    }
    i = 0;
    while(i++ < data->number_of_forks)
    {
        if (pthread_create(&data->philos[i].thread_philo, 0, &func, 0) != 0)
        {
            printf("pthread_create Error!");        
            exit(1);
        }
    }
    i = 0;
    while(i++ < data->number_of_forks)
    {
        if (pthread_join(data->philos[i].thread_philo, 0) != 0)
        {
            printf("pthread_join Error!");        
            exit(1);
        }
    }
}

void get_philosophers(t_data *data)
{
    int i;

    i = 1;
    while(i++ < data->number_of_forks)
    {
        data->philos[i].id = i;
        data->philos[i].left_fork = i;
        data->philos[i].right_fork = (i + 1) % data->number_of_forks;
        data->philos[i].eat_count = 0;
        data->philos[i].last_eat_time = 0;
        data->philos[i].is_done = false;
    }
}