/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:15:23 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/04 01:52:47 by atarchou         ###   ########.fr       */
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
	int				pid;
	int				left;
	int				right;
	int				nb_ate;
	int				is_eating;
}				t_each;

typedef struct s_philo
{
	long long		start;
	t_each			**philosopher;
	pthread_mutex_t	*forks;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
}				t_philo;

int	ft_atoi(char *str);
int	check_arg_validity(int argSize, char **args);

#endif