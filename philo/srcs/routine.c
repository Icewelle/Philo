/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:37:16 by cluby             #+#    #+#             */
/*   Updated: 2024/11/13 13:28:04 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	static long int	start;
	long int		time;
	struct timeval	now;

	time = 0;
	if (gettimeofday(&now, NULL) == -1)
		return (errors(USLEEP), -1);
	time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	if (!start)
		start = time;
	return (time - start);
}

void	ft_usleep(int time)
{
	long int	start;
	
	start = get_time();
	while (get_time() - start < time)
		usleep(150);
}

void	*routine(void *arg)
{
	t_philo		*philos;
	
	philos = (t_philo *)arg;
	if (philos->id % 2 == 1)
		ft_usleep(philos->datas->tte * 0.9 + 1);
	while (philos->datas->is_dead || (philos->meal < philos->datas->nbr_eating))
	{
		eating()
		//sleep
		//think
	}
	return (NULL);
}
