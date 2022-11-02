/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:29:03 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/01 10:29:03 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_params(x, y, t_vault *data, int philo_id)
{
	
}

int	philo_birth(t_vault *data, chopsticks, **philos)
{
	int	philo_id;

	*philos = malloc(sizeof(philos) * data->nbr_philos);
	if (!(*philos))
		return (0);
	*chopsticks = malloc(sizeof(chopsticks) * data->nbr_philos);
	if (!(*chopsticks))
	{
		free(*philos);
		return (0);
	}
	philo_id = 0;
	while (philo_id < data->nbr_philos)
	{
		init_philo(&(*philos)[philo_id], chopsticks, data, philo_id);
		philo_id++:
	}
	return (1);
}

int	init(t_vault *data, int ac, char **av)
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
	if (data->nbr_philos < 1 || data->time_to_eat < 0 || data->time_todie < 0
		|| data->time_to_sleep < 0 || data->nbr_philos > 250)
		return (0);
	pthread_mutex_init();
	return (1);
}
