/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:37:16 by cluby             #+#    #+#             */
/*   Updated: 2024/11/11 13:15:33 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_usleep(int time)
{
	struct timeval start;
	struct timeval now;
	long long time_now;

	gettimeofday(&start, NULL);
	time_now = start.tv_sec * 1000 + start.tv_usec / 1000;
	while (((now.tv_sec * 1000 + now.tv_usec / 1000) - time_now >= time))
	{
		gettimeofday(&now, NULL);
	}
}

void *routine(void *arg)
{
	t_philo		*philos;
	//long long	time;
	philos = (t_philo *)arg;
	
	//put half philo to wait
	if (philos->id % 2 == 1)
	{
		ft_usleep(philos->datas->tte);
		//printf("Philo %d is done waiting\n", philos->id);
	}
	//make the other half start eating
	//make the first half sleeping/thinking while making the other half eating
	return (NULL);
}
