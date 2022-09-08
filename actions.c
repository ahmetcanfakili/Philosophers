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

//timestamp_in_ms X has taken a fork

void status(t_data *data, int i, int msg)
{
    char *states[5] = {"has taken a fork\n", "is eating\n", "is sleeping\n", "is thinking\n", "died\n"};
    printf("%lld, %s", current_time(), data->philos[i].philo_id, states[msg]);
}

// not finished yet
void *dining(int i)
{
    //do stuff
}

void take_forks()
{
    pthread_mutex_lock() //left fork
    status();           //has taken a fork
    pthread_mutex_lock() //right fork
}

void eating()
{
         //is eating status
}

void put_forks()
{
    pthread_mutex_unlock();
    status();
    pthread_mutex_unlock();    
}

void thinking()
{
        //is thinking status
}

void sleeping()
{
        //is sleeping status
}