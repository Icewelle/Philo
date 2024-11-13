/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:26:03 by cluby             #+#    #+#             */
/*   Updated: 2024/11/13 11:16:51 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	only_nbr(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static void	put_datas(t_data *datas, char **argv)
{
	datas->nbr_philo = ft_atoi(argv[1]);
	datas->ttd = ft_atoi(argv[2]);
	datas->tte = ft_atoi(argv[3]);
	datas->tts = ft_atoi(argv[4]);
	if (argv[5])
		datas->nbr_eating = ft_atoi(argv[5]);
}

static t_error	verif_datas(t_data *datas)
{
	if (datas->nbr_philo < 1 || datas->nbr_philo > 200)
		return (TOO_MANY_PHILO);
	if (datas->ttd < 60 || datas->tte < 60 || datas->tts < 60)
		return (MS_TOO_LOW);
	return (OK);
}

t_data	*parsing(char **argv, int argc)
{
	t_data	*datas;
	int		i;

	datas = malloc(sizeof(t_data));
	if (!datas)
		return (datas);
	init_data(datas);
	datas->error = handle_args(argc);
	i = 1;
	while (i < argc)
	{
		if (only_nbr(argv[i]) != true)
			return (datas->error = NOT_ONLY_NUMBERS, datas);
		i++;
	}
	put_datas(datas, argv);
	datas->error = verif_datas(datas);
	return (datas);
}
