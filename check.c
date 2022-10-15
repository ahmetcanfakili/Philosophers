/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <afakili@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:45:11 by afakili           #+#    #+#             */
/*   Updated: 2022/10/15 21:58:36 by afakili          ###   ########.fr       */
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
}

void	dining_checker(t_data *data)
{
}
