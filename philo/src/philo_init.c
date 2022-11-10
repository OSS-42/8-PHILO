/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:29:03 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/10 09:53:49 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_params(t_vault *data, t_philo *philo, t_fork **chopsticks,
	int philo_id)
{
	philo->data = data;
	philo->id = philo_id;
	philo->last_meal = 0;
	philo->meal_count = 0;
	philo->right_chopstick = &((*chopsticks)[philo_id]);
	philo->right_taken = 0;
	philo->left_taken = 0;
	if (philo_id == data->nbr_philos - 1)
		philo->left_chopstick = &((*chopsticks)[0]);
	else
		philo->left_chopstick = &((*chopsticks)[philo_id + 1]);
	philo->left_chopstick->used = 0;
	pthread_mutex_init(&(philo->mutex_last_meal), NULL);
	pthread_mutex_init(&(philo->left_chopstick->lock), NULL);
}

int	philo_birth(t_vault *data, t_fork **chopsticks, t_philo **philo)
{
	int	philo_id;

	*philo = malloc(sizeof(t_philo) * data->nbr_philos);
	if (!(*philo))
		return (0);
	*chopsticks = malloc(sizeof(t_fork) * data->nbr_philos);
	if (!(*chopsticks))
	{
		free(*philo);
		return (0);
	}
	philo_id = 0;
	while (philo_id < data->nbr_philos)
	{
		philo_params(data, &(*philo)[philo_id], chopsticks, philo_id);
		philo_id++;
	}
	return (1);
}

int	init_data(t_vault *data, int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		usage_message();
		return (0);
	}
	arg_conversion(data, av);
	data->cycles = -1;
	if (ac == 6)
	{
		data->cycles = ft_atolong(is_av_digit(av[5]));
		if (data->cycles < 0)
			data->cycles = 0;
	}
	data->is_dead = 0;
	if (data->nbr_philos < 1 || data->time_to_eat <= 0 || data->time_to_die <= 0
		|| data->time_to_sleep <= 0 || data->cycles == 0
		|| data->nbr_philos > 200)
	{
		usage_message();
		return (0);
	}
	pthread_mutex_init(&(data->mutex_is_dead), NULL);
	return (1);
}
