/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:32 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/03 15:51:07 by ewurstei         ###   ########.fr       */
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

/***** main.c *****/

void		philo(t_vault *data);

/***** _libft.c *****/
long		ft_atolong(const char *str);

/***** _utils.c *****/
long long	get_time_stamp(void);

/***** _init.c *****/
int			init(t_vault *data, int ac, char **av);
void		philo_params(x, y, t_vault *data, int philo_id);
int			philo_birth(t_vault *data, chopsticks, **philos);

#endif