/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:14:23 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/04 15:59:23 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	mod_usleep(long time_in_ms)
{
	long	start_time;

	start_time = 0;
	start_time = get_time_stamp();
	while ((get_time_stamp() - start_time) < time_in_ms)
		usleep(100);
	return ;
}

void	print_state(char *str, t_philo *philo)
{
	long	now_time;

	now_time = get_time_stamp() - philo->data->first_timestamp;
	pthread_mutex_lock(&(philo->data->mutex_print_message));
	if (!(is_dead(philo)))
		printf("%09ld %d %s\n", now_time, philo->id, str);
	pthread_mutex_unlock(&(philo->data->mutex_print_message));
	return ;
}

int	print_error(void)
{
	printf("%s", "Error : usage : ./philo 'nbr philos' 'time to die'");
	printf("%s\n", " 'time to eat' 'time to sleep' [nbr meals]");
	return (0);
}

int	print_error2(void)
{
	printf("%s", "Error : unexpected error");
	return (0);
}

long long	get_time_stamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
