/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:24:41 by afakili           #+#    #+#             */
/*   Updated: 2022/08/18 16:24:41 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// struct sorunu çözülecek !!
int main(int argc, char **argv)
{
    t_data data;

    if (!(argc == 5 || argc == 6))
    {
        printf("\e[41mArgument Error!");
        exit(1);
    }
    get_arguments(argc, argv, &data);
    get_mutexes(&data);
    get_threads(&data);
    get_philosophers(&data);
    destroy_mutexes(&data);
    return (0);
}

/*
args:
fork die eat sleep (max_eat)

timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is thinking
timestamp_in_ms X is sleeping
timestamp_in_ms X died
*/
