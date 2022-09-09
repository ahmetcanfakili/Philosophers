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
#include <stdbool.h>

typedef struct s_data t_data;

typedef struct s_philo
{
    int         philo_id;
    int         right_fork;
    int         left_fork;
    int         eat_count;
    bool        is_done;
    long long   last_eat_time;
    t_data      *data;
    pthread_t   thread_id;
} t_philo;

typedef struct s_data
{
    int             number_of_forks;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             must_eat;
    t_philo         *philos;
    pthread_mutex_t *forks;
} t_data;

enum state {
    TAKE_FORK,
    EATING,
    SLEEPING,
    THINKING,
    DIED
};

int	mf_ft_atoi(const char *str);
void get_mutexes(t_data *data);
void get_threads(t_data *data);
void get_arguments(int argc, char **argv, t_data *data);
void get_philosophers(t_data *data);
long long current_time(void);
void *dining(void *philo_arg);
void destroy_mutexes(t_data *data);
void status(t_philo *philo, int msg);
void take_forks(t_philo *philo);
void eating(t_philo *philo);
void put_forks(t_philo *philo);
void thinking(t_philo *philo);
void sleeping(t_philo *philo);

#endif
