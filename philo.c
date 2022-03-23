/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:03:42 by atarchou          #+#    #+#             */
/*   Updated: 2022/03/23 21:06:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*init_fork(t_philo *table)
{
	pthread_mutex_t	*forks;
	int	i;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->nb_philo);
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

t_philo	*fill_table(int argc, char **argv)
{
	t_philo	*table;

	if(table == NULL)
		return(NULL);
	table->philosopher = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->nb_eat = ft_atoi(argv[5]);
	table->forks = init_fork(table);
}

int	main(int argc, char **argv)
{
	t_philo	*table;
	int		philo;

	philo = 0;
	table = NULL;
	
	table = fill_table(argc, argv);
	
}