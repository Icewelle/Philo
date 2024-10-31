/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:43:13 by cluby             #+#    #+#             */
/*   Updated: 2024/10/31 18:08:27 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error	create_structs(t_philo *philos, t_data *datas)
{
	int	i;

	i = 0;
	while (i < datas->nbr_philo)
	{
		philos[i].id = i + 1;
		;
		if (pthread_mutex_init(&philos[i].fork, NULL))
			return (MUTEX);
		if (i == 0)
			philos[i].n_fork = &philos[i - 1].fork;
		if (i == datas->nbr_philo - 1)
			philos[i].n_fork = &philos[0].fork;
		philos[i].meal = 0;
		i++;
	}
	return (OK);
}

t_philo	*init_philos(t_data *datas)
{
	t_philo *philos;

	printf("%d", datas->nbr_philo);
	philos = malloc((datas->nbr_philo) * sizeof(t_philo));
	if (!philos)
		return (datas->error = MALLOC_PHILOS, NULL);
	if ((datas->error = create_structs(philos, datas)) != OK)
		return (free(philos), NULL);
	/* if (datas->error = create_threads(philos))
		return (free(philos), NULL); */
	return (philos);
}