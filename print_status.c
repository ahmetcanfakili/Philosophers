/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:30:33 by afakili           #+#    #+#             */
/*   Updated: 2022/11/28 14:50:48 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	status(t_philo *philo, int msg, uint64_t current_time)
{
	const char	*states[5] = {"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};

	if (!philo->data->running)
		return ;
	pthread_mutex_lock(&philo->data->w_permission);
	printf("%llu, %d, %s\n", current_time - philo->start_time, philo->philo_id, states[msg]);
	pthread_mutex_unlock(&philo->data->w_permission);
}
