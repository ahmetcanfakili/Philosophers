/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:52:01 by afakili           #+#    #+#             */
/*   Updated: 2022/11/28 14:22:49 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_forks)
		pthread_mutex_destroy(&data->forks[i]);
}

void	destroy_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_forks)
	{
		if (pthread_detach(data->philos[i].thread_id) != 0)
		{
			printf("\e[41mpthread_detach Error!\n");
			exit(1);
		}
	}
}

void	destroy_all(t_data *data)
{
	destroy_threads(data);
	destroy_mutexes(data);
	free(data->philos);
	free(data->forks);
}
