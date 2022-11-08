/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:37:06 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/08 11:54:08 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	print_state("is eating", philo);
	pthread_mutex_lock(&(philo->mutex_last_meal));
	philo->last_meal = get_time_stamp() - philo->data->first_timestamp;
	pthread_mutex_unlock(&(philo->mutex_last_meal));
	mod_usleep(philo->data->time_to_eat);
//	pthread_mutex_lock(&(philo->mutex_meal_count));
	philo->meal_count++;
//	pthread_mutex_unlock(&(philo->mutex_meal_count));
	give_back_chopstick_and_sleep(philo);
}

void	*life_of_a_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		mod_usleep(philo->data->time_to_eat);
	while (!(is_dead(philo)))
	{
		if (philo->meal_count >= philo->data->cycles && philo->data->cycles > 0)
			break ;
		take_chopstick('L', philo);
		if (philo->left_taken)
			take_chopstick('R', philo);
		if (philo->right_taken && philo->left_taken)
		{
			philo_eat(philo);
		}
	}
	return (NULL);
}
