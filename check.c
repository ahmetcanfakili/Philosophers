/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <afakili@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:45:11 by afakili           #+#    #+#             */
/*   Updated: 2022/10/18 11:57:51 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_arg_count(int argc)
{
	if (!(argc == 5 || argc == 6))
	{
		printf("\e[41mArgument Error!");
		exit(1);
	}
}

void	check_value(t_data *data)
{
	if (data->number_of_forks > 200)
	{
		printf("\e[41mThe number of philosophers cannot exceed 200!\n");
		exit(1);
	}
	if (data->time_to_die < 60 || data->time_to_eat < 60 || data->time_to_sleep < 60)
	{
		printf("\e[41mArguments cannot be less than 60ms !\n");
		exit(1);

	}
}

void	*dining_checker(void *data_arg)
{
	t_data *data;
	int i;
	uint64_t time_stamp;
	
	i = 0;
	data = (t_data *)data_arg;
	while(1)
	{
		if (data->finished_count == data->number_of_forks)
			break ;
		if (i == data->number_of_forks)
			i = 0;
		usleep(1000);
		time_stamp = current_time();
		if (!data->philos[i].is_done && (int)(time_stamp - data->philos[i].last_eat_time) > data->time_to_die)
		{
			status(&data->philos[i], DIED, current_time());
			data->running = false;
			break ;
		}
		i++;
	}
	return (0);
}
