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
