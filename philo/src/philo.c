/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:06 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/10 09:53:42 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	free_and_quit(t_fork *chopsticks, t_philo *philo)
{
	printf("Unexpected error\n");
	free(philo);
	free(chopsticks);
	return (0);
}

int	main(int ac, char **av)
{
	t_vault	data;
	t_fork	*chopsticks;
	t_philo	*philo;

	if (!(init_data(&data, ac, av)))
		return (0);
	if (!(philo_birth(&data, &chopsticks, &philo)))
		free_and_quit(chopsticks, philo);
	if (!(threads_creation(&data, &philo)))
	{
		threads_killing(&philo[0]);
		free_and_quit(chopsticks, philo);
	}
	if (!(wait_for_all_threads(&data, &philo)))
		free_and_quit(chopsticks, philo);
	pthread_mutex_destroy(&data.mutex_is_dead);
	free(philo);
	free(chopsticks);
	return (0);
}
