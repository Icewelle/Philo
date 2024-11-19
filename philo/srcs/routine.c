/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:37:16 by cluby             #+#    #+#             */
/*   Updated: 2024/11/19 14:57:37 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(t_philo *philo)
{
	if (gettimeofday(&philo->now, NULL) == -1)
		return (errors(USLEEP), -1);
	philo->time = (philo->now.tv_sec * 1000) + (philo->now.tv_usec / 1000);
	return (philo->time - philo->datas->start);
}

void	ft_usleep(int time, t_philo *philo)
{
	long int	start;
	
	start = get_time(philo);
	while (get_time(philo) - start < time)
		usleep(100);
}

static void	eating(t_philo	*philo)
{
    pthread_mutex_lock(&philo->fork);
    print_thread("has taken a fork", philo);
    pthread_mutex_lock(philo->n_fork);
	print_thread("has taken a fork", philo);
	philo->last_meal = get_time(philo);
    print_thread("is eating", philo);
	if (philo->datas->nbr_eating != -1)
		philo->meal++;
    ft_usleep(philo->datas->tte, philo);
    pthread_mutex_unlock(philo->n_fork);
    pthread_mutex_unlock(&philo->fork);
}

static void	sleeping(t_philo	*philo)
{
	print_thread("is sleeping", philo);
	ft_usleep(philo->datas->tts, philo);
}

void	*routine(void *arg)
{
	t_philo		*philos;
	
	philos = (t_philo *)arg;
	if (philos->id % 2 == 0)
		ft_usleep(philos->datas->tte, philos);
	while (philos->datas->is_dead == false)
	{
		if (philos->datas->is_dead == false)
			eating(philos);
		if (philos->datas->is_dead == false)
			sleeping(philos);
		print_thread("is thinking", philos);
	}
	return (NULL);
}
