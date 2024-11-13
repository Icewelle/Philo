/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:33:24 by cluby             #+#    #+#             */
/*   Updated: 2024/11/13 11:16:25 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error	handle_args(int argc)
{
	if (argc < 5 || argc > 6)
		return (NBR_ARGS);
	return (OK);
}

int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
		return (true);
	return (false);
}

void	init_data(t_data *data)
{
	data->nbr_philo = 0;
	data->ttd = 0;
	data->tte = 0;
	data->tts = 0;
	data->nbr_eating = 0;
	data->is_dead = false;
	data->error = OK;
	pthread_mutex_init(&data->mutex, NULL);
}

static void	init_vars(t_varatoi *vars)
{
	vars->digit = 0;
	vars->i = 0;
	vars->is_negative = 1;
	vars->number = 0;
}

int	ft_atoi(const char *str)
{
	t_varatoi	vars;

	init_vars(&vars);
	while ((str[vars.i] >= 9 && str[vars.i] <= 13) || str[vars.i] == 32)
		vars.i++;
	if (str[vars.i] == '-' || str[vars.i] == '+')
	{
		if (str[vars.i] == '-')
			vars.is_negative *= -1;
		vars.i++;
	}
	while (str[vars.i] >= 48 && str[vars.i] <= 57)
	{
		vars.digit = str[vars.i] - 48;
		if (vars.is_negative == 1 && (vars.number > (INT_MAX - vars.digit) \
		/ 10))
			return (INT_MAX);
		if (vars.is_negative == -1 && (-vars.number < (INT_MIN + vars.digit) \
		/ 10))
			return (INT_MIN);
		vars.number = vars.number * 10 + (str[vars.i] - 48);
		vars.i++;
	}
	return (vars.number * vars.is_negative);
}
