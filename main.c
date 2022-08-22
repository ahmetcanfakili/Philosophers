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

int g=0;

void *func(void *arg)
{
    int *id = (int *)arg; 
    printf("ID: %d\n", *id);
    return (0);
}

int main(int argc, char **argv) 
{
    pthread_t thread_id;
    t_philo philo;

    for (int i=0; i<3; i++)
        pthread_create(&thread_id, NULL, func, (void*)&thread_id);
    pthread_exit(NULL);

    if (argc > 1)
    {
        philo.number_of_philosophers = ft_atoi(argv[1]); // == forks_count
        philo.time_to_die = ft_atoi(argv[2]); //ms 
        philo.time_to_eat = ft_atoi(argv[3]); //yemek yerken geçen süre
        philo.time_to_sleep = ft_atoi(argv[4]); //uykuda geçen süre
        philo.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);//(optional)kaç kaç kez yemek yiyeceği-belirtilmezse ilk filozof ölünce program biter. 
    }
    else
        printf("Error!\n");
}

/*
eat
sleep
think
die

timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died

philo == thread
fork == mutex

*/
