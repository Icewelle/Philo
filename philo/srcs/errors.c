/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:31:35 by cluby             #+#    #+#             */
/*   Updated: 2024/10/31 18:57:09 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errors(t_error error)
{
	if (error == NUMBER_ERR)
		printf("Enter a number between 60 and 2147483647. Please. Thank.\n");
	if (error == NBR_ARGS)
	{
		printf("Format : [Nbr_philo] [Time_to_die] [Time_to_eat] ");
		printf("[Time_to_sleep] [Time_to_think] (optioanal [Nbr_of_eating])\n");
	}
	if (error == NOT_ONLY_NUMBERS || error == NEGATIVE_NUMBER)
		printf("Only positive integer numbers are accepted.\n");
	if (error == TOO_MANY_PHILO)
		printf("No more than 200 philo can sit on this table.\n");
	if (error == EMPTY_TABLE)
		printf("At least one philo must sit on the table.");
	if (error == MALLOC_PHILOS)
		printf("Error during memory allocation of : struct t_philo philos\n");
	if (error == MS_TOO_LOW)
		printf("They won't have time to do anything, put over 60 ms please\n");
}
