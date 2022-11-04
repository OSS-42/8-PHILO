/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_kill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:15:34 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/04 11:33:45 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_philo_really_dead(t_philo *philo, long now_time)
{
	int	is_dead;
	int	last_meal;

	is_dead = 0;
	pthread_mutex_lock(&(philo->last_meal));
	last_meal = now_time - philo->last_meal;
	pthread_mutex_unlock(&(philo->last_meal));
	if (last_meal > philo->data->time_to_die)
	{
		pthread_mutex_lock(&(philo->data->mutex_death_call));
		pthread_mutex_lock(&(philo->data->mutex_is_dead));
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&(philo->data->mutex_is_dead));
		printf("%09ld %d just died of starving", now_time, philo->id);
		pthread_mutex_unlock(&(philo->data->mutex_death_call));
		is_dead = 1;
	}
	return (is_dead);
}

void	*is_philo_dead(void *arg)
{
	t_vault	*data;
	t_philo	**philo;
	long	now_time;
	int		philo_id;

	philo = (t_philo **)arg;
	data = philo[0]->data;
	while (1)
	{
		philo_id = 0;
		now_time = get_time_stamp() - data->first_timestamp;
		while (philo_id < data->nbr_philos)
		{
			if (is_philo_really_dead(&(*philo)[philo_id], now_time))
				return (NULL);
			philo_id++;
		}
		mod_usleep(1);
	}
	return (NULL);
}

int	is_dead(t_philo *philo)
{
	int	is_alive;

	pthread_mutex_lock(&(philo->data->mutex_is_dead));
	is_alive = philo->data->is_dead;
	pthread_mutex_unlock(&(philo->data->mutex_is_dead));
	return (is_alive);
}
