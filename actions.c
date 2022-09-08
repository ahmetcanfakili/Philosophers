/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:04:22 by afakili           #+#    #+#             */
/*   Updated: 2022/09/04 17:04:22 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void status(int i)
{
    char *states[5] = {"has taken a fork\n", "is eating\n", "is sleeping\n", "is thinking\n", "died\n"};
    printf("%s", states[i]);
}

// not finished yet
void *dining(int i)
{
    int i;

    i = 0;
    while(i++ < data->number_of_forks)
    {
        pthread_mutex_lock(&data->forks[i]);
        pthread_mutex_lock(&data->forks[(i + 1) % data->number_of_forks]);
    }

    i = 0;
        printf("%lld %d is eating\n", current_time(), data->philos[i].philo_id);
    while(i++ < data->number_of_forks)
    {
        sleep(3);
        pthread_mutex_unlock(&data->forks[i]);
        pthread_mutex_unlock(&data->forks[(i + 1) % data->number_of_forks]);
    }
    printf("%lld %d is finished eating\n", current_time(), data->philos[i].philo_id);
}
