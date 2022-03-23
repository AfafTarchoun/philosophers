/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:15:23 by atarchou          #+#    #+#             */
/*   Updated: 2022/03/23 21:05:40 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <pthread.h>
# include <sys/time.h>

typedef	struct	s_philo
{
	long long	start;
	pthread_t	*philosopher;
	pthread_mutex_t	*forks;
	int			death;
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_eat;
}				t_philo;

int	ft_atoi(char *str);

#endif