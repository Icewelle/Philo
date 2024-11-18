/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:37:16 by cluby             #+#    #+#             */
/*   Updated: 2024/11/18 13:30:30 by cluby            ###   ########.fr       */
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
		usleep(100);
}

static void	eating(t_philo	*philo)
{
	pthread_mutex_lock(&philo->fork);
	print_thread("has taken a fork", philo);
	pthread_mutex_lock(philo->n_fork);
	print_thread("has taken a fork", philo);
	print_thread("is eating", philo);
	ft_usleep(philo->datas->tte);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->n_fork);
}

void	*routine(void *arg)
{
	t_philo		*philos;
	
	philos = (t_philo *)arg;
	if (philos->id % 2 == 1)
		ft_usleep(philos->datas->tte * 0.9 + 1);
	while (philos->datas->is_dead == false)
	{
		eating(philos);
		printf("test\n");
		pthread_mutex_lock(&philos->datas->mutex);
		philos->datas->is_dead = true; //test if watcher see this
		pthread_mutex_unlock(&philos->datas->mutex);
		//sleep
		//think
	}
	return (NULL);
}
