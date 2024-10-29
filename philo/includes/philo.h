/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:42:06 by cluby             #+#    #+#             */
/*   Updated: 2024/10/28 23:32:44 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct s_data
{
	int	nbr_philo;
	int	ttd;
	int	tte;
	int	tts;
	int	nbr_eating;
	int error;
}	t_data;

//utils
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
/*----------------------------------------------------------------------------*/

//parsing
t_args	parsing(char **argv);
/*----------------------------------------------------------------------------*/
