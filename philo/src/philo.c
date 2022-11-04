/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:06 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/04 12:05:58 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_vault	data;
	t_fork	*chopsticks;
	t_philo	*philo;

	if (!(init_data(&data, ac, av)))
		return (-1);
	if (!(philo_birth(&data, &chopsticks, &philo)))
		return (-1);
	if (!(threads_creation(&data, &philo)))
	{
		threads_killing(&philo[0]);
		return (-1);
	}
	if (!(wait_for_all_threads(&data, &philo)))
	{
		free(philo);
		free(chopsticks);
		return (-1);
	}
	free(philo);
	free(chopsticks);
	return (0);
}
