/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:15:18 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/04 01:10:30 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_is_number(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] <= '0' || string[i] >= '9')
			return (-1);
		i++;
	}
	return (3);
}

int	check_arg_validity(int argSize, char **args)
{
	int	i;

	i = 1;
	if (argSize - 1 < 4 || argSize - 1 > 5)
		return (-1);
	while (i < argSize)
	{
		if (args[i][0] == '-' && ft_is_number(args[i]) != 3)
			return (-1);
		i++;
	}
	return (3);
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
	return (num);
}