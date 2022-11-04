/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:14:23 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/04 11:04:10 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time_stamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	take_chopstick(char *which_chopstick, t_philo *philo)
{
	int		*taken;
	t_fork	*chopstick;

	if (!(is_dead(philo)))
	{
		taken = &(philo->right_taken);
		chopstick = philo->right_chopstick;
		if (which_chopstick == "left")
		{
			taken = &(philo->left_taken);
			chopstick = philo->left_chopstick;
		}
		pthread_mutex_lock(&(chopstick->lock));
		if (!(*taken) && !(chopstick->used))
		{
			*taken = 1;
			chopstick->used = 1;
			pthread_mutex_unlock(&(chopstick->lock));
			print_state("has taken chopstick", philo);
		}
		else
			pthread_mutex_unlock(&(chopstick->lock));
	}
}