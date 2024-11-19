/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:58:02 by cluby             #+#    #+#             */
/*   Updated: 2024/11/19 13:00:37 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errors(t_error error)
{
	if (error == NBR_ARGS)
		printf("Error: Wrong number of arguments\n");
	if (error == NOT_ONLY_NUMBERS)
		printf("Error: Arguments must be only numbers\n");
	if (error == NUMBER_ERR)
		printf("Error: Wrong number\n");
	if (error == NEGATIVE_NUMBER)
		printf("Error: Negative number\n");
	if (error == TOO_MANY_PHILO)
		printf("Error: Too many philosophers\n");
	if (error == MALLOC_PHILOS)
		printf("Error: Malloc failed\n");
	if (error == MUTEX)
		printf("Error: Mutex failed\n");
	if (error == EMPTY_TABLE)
		printf("Error: Empty table\n");
	if (error == MS_TOO_LOW)
		printf("Error: Time in ms too low\n");
	if (error == THREAD)
		printf("Error: Thread failed\n");
	if (error == USLEEP)
		printf("Error: Usleep failed\n");
	if (error == NBR_EAT)
		printf("Error: Number of meals must be greater than 0\n");
}
