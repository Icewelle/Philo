/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:20:29 by cluby             #+#    #+#             */
/*   Updated: 2024/11/18 12:45:22 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef enum e_error
{
	OK,
	NBR_ARGS,
	NOT_ONLY_NUMBERS,
	NUMBER_ERR,
	NEGATIVE_NUMBER,
	TOO_MANY_PHILO,
	MALLOC_PHILOS,
	MUTEX,
	EMPTY_TABLE,
	MS_TOO_LOW,
	THREAD,
	USLEEP,
	NBR_EAT
}	t_error;

typedef struct s_data
{
	int				nbr_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nbr_eating;
	bool			is_dead;
	pthread_mutex_t	mutex;
	t_error			error;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meal;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	*n_fork;
	t_data			*datas;
}	t_philo;

typedef struct s_varatoi
{
	int	i;
	int	number;
	int	is_negative;
	int	digit;
}	t_varatoi;

//Utils
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		init_data(t_data *data);
t_error		handle_args(int argc);
void		ft_usleep(int time);
long int	get_time(void);
void		print_thread(char *str, t_philo *philos);
/*----------------------------------------------------------------------------*/
//Parsing
t_data		*parsing(char **argv, int argc);
/*----------------------------------------------------------------------------*/
//Init philo values
t_philo		*init_philos(t_data *datas);
/*----------------------------------------------------------------------------*/
//Routine
t_error		create_threads(t_philo *philo);
void		*routine(void *arg);
//void		eating(t_philo *philo);
/*----------------------------------------------------------------------------*/
//Errors
void		errors(t_error error);
/*----------------------------------------------------------------------------*/

#endif