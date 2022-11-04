/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:32 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/04 10:55:51 by ewurstei         ###   ########.fr       */
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
	int				cycles;
	long			nbr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long long		first_timestamp;
	int				is_dead;
	pthread_mutex_t	console_mutex;
	pthread_mutex_t	mutex_is_dead;
	pthread_t		thread_of_death;
}	t_vault;

typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				used;
}	t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	long			last_meal;
	int				meal_count;
	pthread_mutex_t	mutex_last_meal;
	t_fork			*right_chopstick;
	int				right_taken;
	t_fork			*left_chopstick;
	int				left_taken;
	t_vault			*data;
}	t_philo;


/***** main.c *****/
void		philo(t_vault *data);

/***** _libft.c *****/
long		ft_atolong(const char *str);

/***** _utils.c *****/
long long	get_time_stamp(void);
void		take_chopstick(char *which_chopstick, t_philo *philo);

/***** _init.c *****/
int			init_data(t_vault *data, int ac, char **av);
void		philo_params(t_vault *data, t_philo *philo, t_fork **chopsticks, int philo_id);
int			philo_birth(t_vault *data, chopsticks, **philo);
int			threads_creation(t_vault *data, t_philo **philo);

#endif