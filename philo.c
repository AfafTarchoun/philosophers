/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:03:42 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/14 00:50:40 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_alive(t_each *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->table->nb_philo)
		{
			if (ft_time() - philo->last_eat_time > philo->table->time_to_die)
			{
				if (philo->nb_ate != philo->table->ntpme)
					print_status(philo->table, philo->pid, "died\n");
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	start_threads(t_philo *table)
{
	int	i;

	i = 0;
	table->start = ft_time();
	while (i < table->nb_philo)
	{
		table->philosopher[i]->last_eat_time = ft_time();
		if (pthread_create(&table->philosopher[i]->thd_philo, NULL,
				&start_routine, (void *)table->philosopher[i]) != 0)
			return (-1);
		i++;
		usleep(100);
	}
	is_alive(*table->philosopher);
	return (1);
}

t_philo	*fill_table(int argc, char **argv)
{
	t_philo	*table;
	int		counter;

	counter = 1;
	table = (t_philo *)malloc(sizeof(t_philo) * 1);
	if (table == NULL)
		return (NULL);
	table->nb_philo = ft_atoi(argv[counter++]);
	table->time_to_die = ft_atoi(argv[counter++]);
	table->time_to_eat = ft_atoi(argv[counter++]);
	table->time_to_sleep = ft_atoi(argv[counter++]);
	table->ntpme = -1;
	table->death = 1;
	if (argc - 1 == 5)
		table->ntpme = ft_atoi(argv[counter]);
	table->forks = init_fork(table);
	table->philosopher = init_philo(table);
	if (table->philosopher == NULL || table->nb_philo == 0)
		return (NULL);
	if (pthread_mutex_init(&table->write, NULL) != 0)
		return (NULL);
	return (table);
}

int	main(int argc, char **argv)
{
	t_philo	*table;
	int		philo;

	philo = 0;
	table = NULL;
	if (check_arg_validity(argc, argv) != 1)
	{
		printf("Error: Invalid Argument\n");
		return (-1);
	}
	table = fill_table(argc, argv);
	if (table == NULL)
		return (0);
	start_threads(table);
}
