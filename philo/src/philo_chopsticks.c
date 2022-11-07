/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_chopsticks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:34:51 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/07 13:19:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	give_back_chopstick(char which_chopstick, t_philo *philo)
{
	int		*taken;
	t_fork	*chopstick;

	taken = &(philo->right_taken);
	chopstick = philo->right_chopstick;
	if (which_chopstick == 'L')
	{
		taken = &(philo->left_taken);
		chopstick = philo->left_chopstick;
	}
	pthread_mutex_lock(&(chopstick->lock));
	*taken = 0;
	chopstick->used = 0;
	pthread_mutex_unlock(&(chopstick->lock));
}

void	give_back_chopstick_and_sleep(t_philo *philo)
{
	give_back_chopstick('L', philo);
	give_back_chopstick('R', philo);
	print_state("is now sleeping", philo);
	mod_usleep(philo->data->time_to_sleep);
	if (philo->meal_count >= philo->data->cycles && philo->data->cycles > 0)
		return ;
	print_state("is thinking", philo);
}

void	take_chopstick(char which_chopstick, t_philo *philo)
{
	int		*taken;
	t_fork	*chopstick;

	if (!(is_dead(philo)))
	{
		taken = &(philo->right_taken);
		chopstick = philo->right_chopstick;
		if (which_chopstick == 'L')
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
			print_state("has taken a chopstick", philo);
		}
		else
			pthread_mutex_unlock(&(chopstick->lock));
	}
}
