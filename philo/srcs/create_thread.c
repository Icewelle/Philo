/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:20:45 by cluby             #+#    #+#             */
/*   Updated: 2024/11/19 12:30:11 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_thread(char *str, t_philo *philos)
{
	pthread_mutex_lock(&philos->datas->mutex);
	if (philos->datas->is_dead == false)
		printf("%ld %d %s\n", get_time(), philos->id, str);
	pthread_mutex_unlock(&philos->datas->mutex);
}

void	ft_watcher(t_philo *philos)
{
	int	i;
	int	nbr_philo;
	
	nbr_philo = philos->datas->nbr_philo;
	i = -1;
	while (i++ < nbr_philo - 1)
	{
		pthread_mutex_lock(&philos[i].datas->mutex);
		if (philos[i].datas->nbr_philo < 2)
			philos[i].datas->is_dead = true;
		if (philos[i].datas->is_dead == true)
		{
			philos[i].datas->is_dead = true;
			printf("%ld %d died\n", get_time(), philos[i].id);
		}
		//printf("time = %ld || result = %ld", get_time(), philos[i].last_meal + philos[i].datas->ttd);
		if (get_time() > (philos[i].last_meal + philos[i].datas->ttd))
		{
			philos[i].datas->is_dead = true;
			printf("%ld %d died\n", get_time(), philos[i].id);
		}
		pthread_mutex_unlock(&philos[i].datas->mutex);
	}
}

void	set_start(long int	*start)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return;
	(*start) = (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

t_error	create_threads(t_philo *philos)
{
	int	i;
	int	nbr_philos;

	i = 0;
	nbr_philos = philos[0].datas->nbr_philo;
	set_start(&philos->datas->start);
	while (i < nbr_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
			return (philos[i].datas->error = THREAD);
		i++;
	}
	i = 0;
	while (philos->datas->is_dead == false)
	{
		ft_watcher(philos);
		usleep(150);
	}
	while (i < nbr_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (OK);
}
