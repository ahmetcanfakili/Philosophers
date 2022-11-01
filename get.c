/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <afakili@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:11 by afakili           #+#    #+#             */
/*   Updated: 2022/11/01 22:38:36 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_arguments(int argc, char **argv, t_data *data)
{
	data->number_of_forks = mf_ft_atoi(argv[1]);
	data->time_to_die = mf_ft_atoi(argv[2]);
	data->time_to_eat = mf_ft_atoi(argv[3]);
	data->time_to_sleep = mf_ft_atoi(argv[4]);
	if (argc == 5)
		data->must_eat = 0;
	else
		data->must_eat = mf_ft_atoi(argv[5]);
	data->running = true;
	check_value(data);
}

void	get_mutexes(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_forks);
	if (!data->forks)
	{
		printf("\e[41mMalloc Error! (data->forks)\n");
		exit(1);
	}
	while (++i < data->number_of_forks)
	{
		if (pthread_mutex_init(&data->forks[i], 0) != 0)
		{
			printf("\e[41mpthread_mutex_init Error!\n");
			exit(1);
		}
	}
	pthread_mutex_init(&data->w_permission, NULL);
}

void	get_threads(t_data *data)
{
	int	i;
	pthread_t dining_id;

	i = -1;
	while (++i < data->number_of_forks)
	{
		pthread_create(&data->philos[i].thread_id, 0, &dining, &data->philos[i]);
		// if (pthread_create(&data->philos[i].thread_id, 0, &dining, &data->philos[i]) != 0)
		// {
		// 	printf("\e[41mpthread_create Error!\n");
		// 	exit(1);
		// }
	}
	i = -1;
	// while (++i < data->number_of_forks)
	// {
	// 	if (pthread_join(data->philos[i].thread_id, 0) != 0)
	// 	{
	// 		printf("\e[41mpthread_join Error!\n");
	// 		exit(1);
	// 	}
	// }
	pthread_create(&dining_id, 0, &dining_checker, data);
	pthread_join(dining_id, 0);
}

void	get_philosophers(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->number_of_forks);
	if (!data->philos)
	{
		printf("\e[41mMalloc Error! (data->philos)\n");
		exit(1);
	}
	while (++i < data->number_of_forks)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % data->number_of_forks;
		data->philos[i].eat_count = 0;
		data->philos[i].last_eat_time = 0;
		data->philos[i].is_done = false;
		data->philos[i].data = data;
		data->philos[i].thread_id = 0;
	}
}
