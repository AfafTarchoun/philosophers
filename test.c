/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:40:48 by atarchou          #+#    #+#             */
/*   Updated: 2022/04/04 01:56:56 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_get_time(int current_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec - current_time);
}

int	main(void)
{
	struct timeval	time;
	int				ret;
	int				i;
	int				t;

	i = 0;
	t = ft_get_time(time.tv_sec);
	gettimeofday(&time, NULL);
	while (i < 10)
	{
		ret = ft_get_time(time.tv_sec);
		printf("%d \n", ret);
		sleep(2);
		i++;
	}
	return (0);
}
