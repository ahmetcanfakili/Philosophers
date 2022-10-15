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

void status(t_philo *philo, int msg, uint64_t current_time)
{
    char *states[5] = {"has taken a fork\n", "is eating\n", "is sleeping\n", "is thinking\n", "died\n"};
    if (!philo->data->running)
        return ;
    pthread_mutex_lock(&philo->data->w_permission);
    printf("%lld, %d, %s\n", current_time, philo->philo_id, states[msg]);
    pthread_mutex_unlock(&philo->data->w_permission);
}

void take_forks(t_philo *philo)
{
    if (pthread_mutex_lock(&philo->data->forks[philo->left_fork]) != 0)
    {
        printf("\e[41mpthread_mutex_lock Error!\n");
        exit(1);
    }
    status(philo, TAKE_FORK, current_time());
    if (pthread_mutex_lock(&philo->data->forks[philo->right_fork]) != 0)
    {
        printf("\e[41mpthread_mutex_lock Error!\n");
        exit(1);
    }
    status(philo, TAKE_FORK, current_time());
}

void eating(t_philo *philo)
{
    philo->eat_count++;
    status(philo, EATING, current_time());
    philo->last_eat_time = current_time();
    usleep(philo->data->time_to_eat * 1000);
}

void put_forks(t_philo *philo)
{
    if ( pthread_mutex_unlock(&philo->data->forks[philo->left_fork]) != 0)
    {
        printf("\e[41mpthread_mutex_unlock Error!\n");
        exit(1);
    }

    if (pthread_mutex_unlock(&philo->data->forks[philo->right_fork]) != 0)
    {
        printf("\e[41mpthread_mutex_unlock Error!\n");
        exit(1);
    }
}

void thinking(t_philo *philo)
{
    status(philo, THINKING, current_time());
}

void sleeping(t_philo *philo)
{
    status(philo, SLEEPING, current_time());
    usleep(philo->data->time_to_sleep * 1000);
}
