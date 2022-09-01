/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:11 by afakili           #+#    #+#             */
/*   Updated: 2022/09/01 18:06:50 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data *get_data(int argc, char **argv)
{
	t_data *data;
    data = malloc(sizeof(t_data));
    if (!data)
        printf("Malloc Error!");
    data->number_of_forks = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		data->number_of_eat = 0;
	else
		data->number_of_eat = ft_atoi(argv[5]);
    data->start_time_in_ms = current_time_in_ms();
    return (data);
}

void get_fork(int count)
{
    size_t i;

    i = 0;
    pthread_mutex_t *mutex_fork;
    mutex_fork = malloc(sizeof(pthread_mutex_t) * count);
    if (!mutex_fork)
    {
        printf("Malloc Error! (murex_fork)");           
        free(mutex_fork);
    }
    while (i++ < count)
        pthread_mutex_init(&mutex_fork[i], 0);
}