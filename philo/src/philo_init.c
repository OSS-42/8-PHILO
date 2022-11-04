/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:29:03 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/04 11:25:54 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	if (pthread_create(&(data->thread_of_death), NULL, is_philo_dead, philo))
		return (0);
	return (1);
}

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

	*philo = malloc(sizeof(philo) * data->nbr_philos);
	if (!(*philo))
		return (0);
	*chopsticks = malloc(sizeof(chopsticks) * data->nbr_philos);
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
	if (ac < 5)
	{
		printf("%s", "Error : usage : ./philo 'nbr philos' 'time to die'");
		printf("%s\n", " 'time to eat' 'time to sleep' [nbr meals]");
		return (0);
	}
	data->cycles = -1;
	if (ac == 6)
	{
		data->cycles = ft_atolong(av[5]);
		if (data->cycles < 0)
			return (0);
	}
	data->nbr_philos = ft_atolong(av[1]);
	data->time_to_die = ft_atolong(av[2]);
	data->time_to_eat = ft_atolong(av[3]);
	data->time_to_sleep = ft_atolong(av[4]);
	data->is_dead = 0;
	if (data->nbr_philos < 1 || data->time_to_eat < 0 || data->time_to_die < 0
		|| data->time_to_sleep < 0 || data->nbr_philos > 250)
		return (0);
	pthread_mutex_init(&(data->mutex_death_call), NULL);
	pthread_mutex_init(&(data->mutex_is_dead), NULL);
	return (1);
}
