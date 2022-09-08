/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:05:00 by afakili           #+#    #+#             */
/*   Updated: 2022/09/08 15:05:00 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// not finished yet
void *dining(void *philo_arg)
{
    t_philo *philo;

    philo = (t_philo *)philo_arg;
    take_forks(philo);
    eating(philo);
    thinking(philo);
    sleeping(philo);
    put_forks(philo); 
    return(0);
}