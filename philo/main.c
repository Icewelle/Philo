/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:19:08 by cluby             #+#    #+#             */
/*   Updated: 2024/11/18 12:11:45 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*datas;
	t_philo	*philos;

	datas = parsing(argv, argc);
	if (!datas)
		return (0);
	if (datas->error != OK)
		return (errors(datas->error), free(datas), 0);
	philos = init_philos(datas);
	if (!philos)
		return (errors(datas->error), 0);
	create_threads(philos);
	if (datas->error != OK)
		return (errors(datas->error), free(philos), free(datas), 0);
	free(philos);
	free(datas);
	return (1);
}
