/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:25:02 by afakili           #+#    #+#             */
/*   Updated: 2022/08/18 16:25:02 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data
{
    int             number_of_forks;
    pthread_mutex_t *forks;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             number_of_eat;
    long long       start_time_in_ms;
} t_data;

long long current_time_in_ms(void);
int	ft_atoi(const char *str);
t_data *get_data(int argc, char **argv);
pthread_mutex_t *get_fork(int count);
void *func(void *arg);
pthread_t *get_philo(t_data *data);

#endif
