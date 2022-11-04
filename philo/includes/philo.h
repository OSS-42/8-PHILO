/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:32 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/04 14:15:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
//# include <semaphore.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_vault
{
	long			cycles;
	long			nbr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long long		first_timestamp;
	int				is_dead;
	pthread_mutex_t	mutex_print_message;
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
void		mod_usleep(long time_in_ms);
void		print_state(char *str, t_philo *philo);

/***** _chopsticks.c *****/
void		take_chopstick(char which_chopstick, t_philo *philo);
void		give_back_chopstick_and_sleep(t_philo *philo);
void		give_back_chopstick(char which_chopstick, t_philo *philo);

/***** _threads.c *****/
int			threads_creation(t_vault *data, t_philo **philo);
int			wait_for_all_threads(t_vault *data, t_philo **philo);
void		threads_killing(t_philo *philo);

/***** _init.c *****/
int			init_data(t_vault *data, int ac, char **av);
void		philo_params(t_vault *data, t_philo *philo, t_fork **chopsticks, int philo_id);
int			philo_birth(t_vault *data, t_fork **chopsticks, t_philo **philo);

/***** _simu.c *****/
void		*life_of_a_philo(void *arg);

/***** _dead.c *****/
int			is_dead(t_philo *philo);
void		*is_philo_dead(void *arg);
int			is_philo_really_dead(t_philo *philo, long now_time);

#endif