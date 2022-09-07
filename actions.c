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

// not finished yet
void status(t_data *data)
{
    int i;

    i = 0;
    printf("%lld %d %s", current_time(), data->philos[i].philo_id, "message");  //write message function!
}

// not finished yet
void *dining(t_data *data)
{
    int i;

        status(data);
    i = 0;
    while(i++ < data->number_of_forks)
    {
        pthread_mutex_lock(&data->forks[i]);
        pthread_mutex_lock(&data->forks[(i + 1) % n]);
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
