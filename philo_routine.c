/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:31:03 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/15 20:19:15 by atarchou         ###   ########.fr       */
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
		usleep(100);
}

void	philo_activity(t_each *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left]);
	print_status(philo->table, philo->pid, "has taken a fork\n");
	pthread_mutex_lock(&philo->table->forks[philo->right]);
	print_status(philo->table, philo->pid, "has taken a fork\n");
	philo->last_eat_time = ft_time();
	print_status(philo->table, philo->pid, "is eating\n");
	philo->is_eating = 1;
	ft_sleep(philo->table->time_to_eat);
	philo->nb_ate += 1;
	pthread_mutex_unlock(&philo->table->forks[philo->right]);
	pthread_mutex_unlock(&philo->table->forks[philo->left]);
	print_status(philo->table, philo->pid, "is sleeping\n");
	ft_sleep(philo->table->time_to_sleep);
	print_status(philo->table, philo->pid, "is thinking\n");
	philo->is_eating = 0;
}

void	*start_routine(void *data)
{
	t_each	*philo;
	int		i;

	philo = (t_each *)data;
	i = 0;
	while (i < philo->table->ntpme || philo->table->death == 1)
	{
		philo_activity(philo);
		if (philo->nb_ate == philo->table->ntpme)
			philo->table->death = 0;
		i++;
	}
	return (NULL);
}
