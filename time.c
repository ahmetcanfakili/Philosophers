/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:28:37 by afakili           #+#    #+#             */
/*   Updated: 2022/09/01 15:39:22 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long current_time_in_ms(void)
{
    long long time;
    struct timeval current_time;
    gettimeofday(&current_time, 0);
    time =(current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return (time);
}
