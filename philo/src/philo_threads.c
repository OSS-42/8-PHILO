/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:47:39 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/08 11:39:38 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	threads_killing(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_is_dead));
	philo->data->is_dead = 1;
	pthread_mutex_unlock(&(philo->data->mutex_is_dead));
	return ;
}

int	wait_for_all_threads(t_vault *data, t_philo **philo)
{
	int	philo_id;
	int	return_flag;

	philo_id = 0;
	return_flag = 1;
	while (philo_id < data->nbr_philos)
	{
		if (pthread_join((*philo)[philo_id].thread, NULL))
			return_flag = 0;
		pthread_mutex_destroy(&(*philo)[philo_id].mutex_last_meal);
//		pthread_mutex_destroy(&(*philo)[philo_id].mutex_meal_count);
		pthread_mutex_destroy(&(*philo)[philo_id].left_chopstick->lock);
		philo_id++;
	}
	return (return_flag);
}

int	threads_creation(t_vault *data, t_philo **philo)
{
	int	philo_id;

	data->first_timestamp = get_time_stamp();
	philo_id = 0;
	while (philo_id < data->nbr_philos)
	{
		if (pthread_create(&((*philo)[philo_id].thread), NULL, life_of_a_philo,
			&((*philo))[philo_id]))
			return (0);
		philo_id++;
	}
	if (is_philo_dead(philo))
		return (0);
	return (1);
}
