/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:20:45 by cluby             #+#    #+#             */
/*   Updated: 2024/11/18 13:30:07 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_thread(char *str, t_philo *philos)
{
	pthread_mutex_lock(&philos->fork);
	printf("%ld %d %s\n", get_time(), philos->id, str);
	pthread_mutex_unlock(&philos->fork);
}

bool	ft_watcher(t_philo *philos)
{
	bool	end;

	end = false;

	pthread_mutex_lock(&philos->datas->mutex);
	if (philos->datas->nbr_philo < 2)
		philos->datas->is_dead = true;
	if (philos->datas->is_dead == true)
	{
		print_thread("died", philos);
		end = true;
	}
	pthread_mutex_unlock(&philos->datas->mutex);
	return (end);
}

t_error	create_threads(t_philo *philos)
{
	int	i;
	int	nbr_philos;

	i = 0;
	nbr_philos = philos[0].datas->nbr_philo;
	while (i < nbr_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
			return (philos[i].datas->error = THREAD);
		i++;
	}
	i = 0;
	while (ft_watcher(philos) == false)
	{
		printf("test w\n");
		usleep(1000000);
	}
	while (i < nbr_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (OK);
}
