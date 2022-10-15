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
	take_forks(philo);
	eating(philo);
	put_forks(philo); 
	thinking(philo);
	sleeping(philo);
	return(0);
}
