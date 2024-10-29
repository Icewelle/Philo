/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:33:24 by cluby             #+#    #+#             */
/*   Updated: 2024/10/28 23:30:17 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	is_negative;

	i = 0;
	number = 0;
	is_negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * is_negative);
}
