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
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             number_of_eat;
    pthread_mutex_t *forks;
    t_philo         *philos;
} t_data;

typedef struct s_philo
{
    int         id;
    pthread_t   thread_p;
} t_philo;

long long current_time_in_ms(void);
int	ft_atoi(const char *str);
void get_arguments(int argc, char **argv, t_data *data);
void get_fork(t_data *data);
void *func(void *arg);
void get_threads(t_data *data);

#endif
