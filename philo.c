/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:03:42 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/04 01:53:27 by atarchou         ###   ########.fr       */
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
	philosopher = (t_each **)malloc(sizeof(t_each *) * table->nb_philo);
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
		philosopher[i]->pid = i;
		philosopher[i]->is_eating = 0;
		philosopher[i]->nb_ate = 0;
		philosopher[i]->left = i;
		philosopher[i]->right = (i + 1) % philosopher[i]->table->nb_philo;
		printf("philo pid is :%d his left fork: %d his right fork: %d\n", philosopher[i]->pid ,philosopher[i]->left, philosopher[i]->right);
		i++;
	}
	return (philosopher);
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
	table->nb_eat = -1;
	if (argc - 1 == 5)
		table->nb_eat = ft_atoi(argv[counter]);
	table->forks = init_fork(table);
	table->philosopher = init_philo(table);
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
}
