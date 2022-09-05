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


void eating(t_data *data)
{
    printf("%lld %d is eating", current_time_in_ms(), data->philos[i].philo_id);
}

void sleeping(t_data *data)
{   
    printf("%lld %d is sleeping", current_time_in_ms(), data->philos[i].philo_id);
}

void thinking(t_data *data)
{
    printf("%lld %d is thinking", current_time_in_ms(), data->philos[i].philo_id);   
}

void died(t_data *data)
{
    printf("%lld %d died", current_time_in_ms(), data->philos[i].philo_id);   
}
*/

void *dining(int n) // n = fork count
{
    int i;

        printf("%lld %d is thinking\n", current_time_in_ms(), n);
    i = 0;
    while(i++ < data->number_of_forks)
    {
        pthread_mutex_lock(&data->forks[i]);
        pthread_mutex_lock(&data->forks[(i + 1) % n]);
    }

    i = 0;
        printf("%lld %d is eating\n", current_time_in_ms(), data->philos[i].philo_id);
    while(i++ < data->number_of_forks)
    {
        sleep(3);
        pthread_mutex_unlock(&data->forks[i]);
        pthread_mutex_unlock(&data->forks[(i + 1) % data->number_of_forks]);
    }
    printf("%lld %d is finished eating\n", current_time_in_ms(), data->philos[i].philo_id);
}
