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

void	*dining(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	philo->last_eat_time = current_time();
	if (philo->philo_id % 2 == 0)
	{
		thinking(philo);
		usleep(philo->data->time_to_eat * 1000);
	}
	while(philo->data->running)
	{
		take_forks(philo);
		eating(philo);
		put_forks(philo); 
		thinking(philo);
		if (philo->eat_count == philo->data->must_eat)
		{
			philo->is_done = true;
			philo->data->finished_count++;
			break;
		}
		sleeping(philo);
	}
	return(0);
}
