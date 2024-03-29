/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:15:18 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/15 20:23:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] == '-' && !str[i + 1])
				return (0);
			else if (str[i] == '+' && !str[i + 1])
				return (0);
			else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
				return (1);
			else if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
				return (0);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(&str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_arg_validity(int argSize, char **args)
{
	int	i;

	i = 1;
	if (argSize - 1 < 4 || argSize - 1 > 5)
		return (0);
	while (i < argSize)
	{
		if ((check_digit(args[i]) != 1) || ft_atoi(args[i]) < 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	print_status(t_philo *table, int id, char *str)
{
	pthread_mutex_lock(&table->write);
	printf("%lld %d %s", ft_time() - table->start, id + 1, str);
	pthread_mutex_unlock(&table->write);
}
