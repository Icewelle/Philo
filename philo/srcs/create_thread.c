/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:20:45 by cluby             #+#    #+#             */
/*   Updated: 2024/11/13 12:04:42 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error	create_threads(t_philo *philo)
{
	int	i;
	int	nbr_philo;

	i = 0;
	nbr_philo = philo[0].datas->nbr_philo;
	while (i < nbr_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (philo[i].datas->error = THREAD);
		i++;
	}
	i = 0;
	while (i < nbr_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (OK);
}
