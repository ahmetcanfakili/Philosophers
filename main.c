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

int main(int argc, char **argv)
{
    if (!(argc == 5 || argc == 6))
    {
        printf("Argument Error1");
        exit(1);
    }
    get_data(argc, argv);
    



}

/*
args:
fork die eat sleep (max_eat)





eat
sleep
think
die

timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died

*/

