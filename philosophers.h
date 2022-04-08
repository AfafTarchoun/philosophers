/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:15:23 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/08 02:39:25 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <pthread.h>
# include <sys/time.h>

typedef struct s_each
{
	pthread_mutex_t	eating;
	struct s_philo	*table;
	pthread_t		thd_philo;
	pthread_t		alive;
	int				pid;
	int				left;
	int				right;
	int				nb_ate;
	long long		last_eat_time;
	int				is_eating;
}				t_each;

typedef struct s_philo
{
	pthread_mutex_t	*forks;
	t_each			**philosopher;
	pthread_mutex_t	write;
	long long		start;
	int				nb_philo;
	int				death;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				nb_eat;
}				t_philo;

void			*start_routine(void *data);
void			print_status(t_philo *table, int id, char *str);
long long		ft_time(void);
int				ft_atoi(char *str);
int				check_arg_validity(int argSize, char **args);
t_each			**init_philo(t_philo *table);
pthread_mutex_t	*init_fork(t_philo *table);
pthread_mutex_t	*init_fork(t_philo *table);
t_each			**init_philo(t_philo *table);

#endif