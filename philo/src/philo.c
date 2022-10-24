/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:06 by ewurstei          #+#    #+#             */
/*   Updated: 2022/10/24 17:18:17 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo(t_vault *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_create();


 join is performed when one wants to wait for a thread to finish. A thread calling routine may launch multiple threads then wait for 
 them to finish to get the results. One wait for the completion of the threads with a join. 
for(i=0; i < NTHREADS; i++)
   {
      pthread_create( &thread_id[i], NULL, thread_function, NULL );
   }

   for(j=0; j < NTHREADS; j++)
   {
      pthread_join( thread_id[j], NULL); 
   }
  





		
		i++;
	}
	return ;
}

void	init(t_vault *data)
{
	if (data->agc == 6)
		data->cycles = ft_atolong(data->agv[5]);
	else
		data->cycles = 999;
	data->nbr_philos = ft_atolong(data->agv[1]);
	data->chopsticks = data->nbr_philos;
	data->time_to_die = ft_atolong(data->agv[2]);
	data->time_to_eat = ft_atolong(data->agv[3]);
	data->time_to_sleep = ft_atolong(data->agv[4]);
	return ;
}

int	main(int ac, char **av)
{
	t_vault data;
	
	if (ac == 5 || ac == 6)
	{
		data.agv = av;
		data.agc = ac;
		data.nbr_ac = ac - 1;
		init(&data);
		philo(&data);
	}
	else
		printf("%sn", "Error : usage : ./philo 'qty philo' 'time to die' 'time to eat' 'time to sleep' [cycles]");
	return (0);
}



/*
void	*print_message_function(void *ptr)
{
	char	*message;

	message = (char *) ptr;
	printf("%s \n", message);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	char		*message1;
	char		*message2;
	int			iret1;
	int			iret2;

	/* Create independent threads each of which will execute function
	message1 = "Thread 1";
	message2 = "Thread 2";
	iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
	iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);

	/* Wait till threads are complete before main continues. Unless we
	/* wait we run the risk of executing an exit which will terminate
	/* the process and all threads before the threads have completed.

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL); 

	printf("Thread 1 returns: %d\n",iret1);
	printf("Thread 2 returns: %d\n",iret2);
	exit(0);
}
*/