/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:31:03 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/08 01:21:32 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	ft_sleep(int x)
{
	long	i;
	long	o;

	o = (long)x;
	i = ft_time();
	while (ft_time() - i < x)
		usleep(500);
}

void	eating(t_each *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left]);
	print_status(philo->table, philo->pid, "has taken a fork\n");
	pthread_mutex_lock(&philo->table->forks[philo->right]);
	print_status(philo->table, philo->pid, "has taken a fork\n");
	pthread_mutex_lock(&philo->eating);
	print_status(philo->table, philo->pid, "is eating\n");
	philo->last_eat_time = ft_time();
	philo->is_eating = 1;
	usleep(philo->table->time_to_eat * 1000);
	philo->nb_ate++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(&philo->table->forks[philo->left]);
	pthread_mutex_unlock(&philo->table->forks[philo->right]);
}

void	sleeping(t_each *philo)
{
	ft_sleep(philo->table->time_to_sleep);
	print_status(philo->table, philo->pid, "is sleeping\n");
	ft_sleep(philo->table->time_to_sleep);
}

void	thinking(t_each *philo)
{
	print_status(philo->table, philo->pid, "is thinking\n");
}

void	*start_routine(void *data)
{
	t_each	*philo;

	philo = (t_each *)data;
	while (philo->table->death)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		usleep(100);
	}
	return (NULL);
}
