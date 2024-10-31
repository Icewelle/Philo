/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:19:08 by cluby             #+#    #+#             */
/*   Updated: 2024/10/31 18:05:19 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo *philos;

	data = parsing(argv, argc);
	if (data->error != OK)
		return (errors(data->error), free(data),  0);
	philos = init_philos(data);
	if (!philos)
		return (errors(data->error), 0);
	//printf("%d\n", data->nbr_philo);
	free(philos);
	free(data);
	return (1);
}
