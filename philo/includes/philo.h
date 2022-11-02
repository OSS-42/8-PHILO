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
//# include <stdlib.h>
//# include <stdio.h>
# include <pthread.h>
//# include <semaphore.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_vault
{
	int			cycles;
	long		nbr_philos;
	long		chopsticks;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long long	first_timestamp;
	int			is_dead;
}	t_vault;

/***** LIBFT FUNCT. *****/
long		ft_atolong(const char *str);

/***** LOGIQUE *****/
void		init(t_vault *data, int ac, char **av);
void		philo(t_vault *data);
long long	get_time_stamp(void)

/***** ESSAI *****/
void		*print_message_function(void *ptr);

#endif