/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:32 by ewurstei          #+#    #+#             */
/*   Updated: 2022/10/24 16:51:04 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_vault
{
	char 		**agv;
	int			agc;
	int			nbr_ac;
	int			cycles;
	long		nbr_philos;
	long		chopsticks;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long long	first_timestamp;
}	t_vault;

/***** LIBFT FUNCT. *****/
long	ft_atolong(const char *str);

/***** LOGIQUE *****/
void	init(t_vault *data);
void	philo(t_vault *data);

/***** ESSAI *****/
void	*print_message_function(void *ptr);

#endif