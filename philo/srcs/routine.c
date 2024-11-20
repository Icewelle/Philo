/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:37:16 by cluby             #+#    #+#             */
/*   Updated: 2024/11/20 10:55:21 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	static long int	start;
	long int		time;
	struct timeval	now;


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
	philo->last_meal = get_time();
	if (philo->datas->nbr_eating != -1)
		philo->meal++;
    ft_usleep(philo->datas->tte);
    print_thread("is eating", philo);
    pthread_mutex_unlock(philo->n_fork);
    pthread_mutex_unlock(&philo->fork);
}

static void	sleeping(t_philo	*philo)
{
	ft_usleep(philo->datas->tts);
	print_thread("is sleeping", philo);
}

void	*routine(void *arg)
{
	t_philo		*philos;
	
	philos = (t_philo *)arg;
	pthread_mutex_lock(&philos->datas->mutex);
	if (philos->id % 2 == 0)
		ft_usleep(philos->datas->tte);
	while (philos->datas->is_dead == false)
	{
		pthread_mutex_unlock(&philos->datas->mutex);
		eating(philos);
		sleeping(philos);
		print_thread("is thinking", philos);
		pthread_mutex_lock(&philos->datas->mutex);
	}
	pthread_mutex_unlock(&philos->datas->mutex);
	return (NULL);
}
