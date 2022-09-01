/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:11 by afakili           #+#    #+#             */
/*   Updated: 2022/09/01 16:22:18 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void  get_data(int argc, char **argv)
{
	t_data *data;
    data = malloc(sizeof(t_data));
    if (!data)
        printf("Malloc Error!");
    data->number_of_forks = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);

	if (argc == 5)
		data->number_of_eat = 0;
	
	if (argc == 6)
		data->number_of_eat = ft_atoi(argv[5]);
}