/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:46:12 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/09 01:44:42 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*init_fork(t_philo *table)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->nb_philo);
	if (forks == NULL)
		return (NULL);
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}

t_each	**init_philo(t_philo *table)
{
	t_each	**philosopher;
	int		i;

	i = 0;
	philosopher = (t_each **)malloc(sizeof(t_each *) * table->nb_philo + 1);
	if (philosopher == NULL)
		return (NULL);
	while (i < table->nb_philo)
	{
		philosopher[i] = (t_each *)malloc(sizeof(t_each) * 1);
		if (philosopher[i] == NULL)
			return (NULL);
		if (pthread_mutex_init(&philosopher[i]->eating, 0) != 0)
			return (NULL);
		philosopher[i]->table = table;
		philosopher[i]->pid = i ;
		philosopher[i]->is_eating = 0;
		philosopher[i]->nb_ate = 0;
		philosopher[i]->left = i;
		philosopher[i]->right = (i + 1) % philosopher[i]->table->nb_philo;
		i++;
	}
	return (philosopher);
}

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
