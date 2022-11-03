/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:06 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/03 15:09:32 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_vault	data;
	int		error_code;

	error_code = EXIT_SUCCESS;
	if (!(init(&data, ac, av)))
		return (EXIT_FAILURE);

	return (0);
}

/*
int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	index;
	int	sum;
	int	j;
	
	index = *(int *)arg;
	j = 0;
	sum = 0;
	while (j < 5)
	{
		sum = sum + primes[index];
		index++;
		j++;
	}
	printf("Local sum = %d\n", sum);
	*(int *)arg = sum;
	return (arg);
}

int	main(int ac, char **av)
{
	pthread_t	th[2];
	int	i;
	int	*a;
	(void)	ac;
	(void)	av;
	int	*result;
	int	global_sum;

	i = -1;
	while (++i < 2)
	{
		a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("Failed to create thread)");
	}
	i = 0;
	global_sum = 0;
	while (i < 2)
	{
		if (pthread_join(th[i], (void *)&result) != 0)
			perror("Failed to join thread)");
		global_sum = global_sum + (*result);
		free(result);
		i++;
	}
	printf("Global sum = %d\n", global_sum);
	return (0);
}
*/


// void	*roll_dice()
// {
// 	int	value;
// 	int	*result;

// 	result = malloc((sizeof(int)));
// 	value = (rand() % 6) + 1;
// 	*result = value;
// 	//printf("%d\n", value);
// 	printf("Thread result : %p\n", result);
// 	return (void *) result;
// }

// int	main(int ac, char **av)
// {
// 	(void)	ac;
// 	(void)	av;
// 	srand(time(NULL));
// 	pthread_t	th;
// 	int	*res;

// 	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
// 		return (1);
// 	if (pthread_join(th, (void **) &res) != 0)
// 		return (2);
// 	printf("result : %d\n", *res);
// 	printf("Main res: %p\n", res);
// 	free(res);
// 	return (0);
// }

// int	mails = 0;
// pthread_mutex_t	mutex;

// void *routine()
// {
// 	int	i;

// 	i = 0;
// 	while (i < 10000000)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		mails++;
// 		i++;
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	return NULL;
// }

// int	main(int ac, char **av)
// {
// 	pthread_t	th[4];
// 	int			i;
// 	(void)	ac;
// 	(void)	av;

// 	pthread_mutex_init(&mutex, NULL);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
// 		{
// 			perror("Failed to create thread");
// 			return (1);
// 		}
// 		printf("thread %d has started \n", i);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (pthread_join(th[i], NULL) != 0)
// 			return (2);
// 		printf("thread %d has ended\n", i);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("Number of mails : %d\n", mails);
// 	return (0);
// }