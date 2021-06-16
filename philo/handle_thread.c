#include "philo.h"

static int
	create_thread_group(t_public *public, int from)
{
	int		ret;
	void	*arg;
	int		i;

	ret = 0;
	i = from;
	while (!ret && i < public->nop)
	{
		arg = &(public->philo[i]);
		ret = pthread_create(&public->philo[i].thread_id, NULL, &philo_routine, arg);
		if (!ret && i == 0)
			usleep(100);
		i += 2;
	}
	return (ret);
}

int
	handle_thread(t_public *public)
{
	int		i;
	int		ret;
	int		status;

	ret = create_thread_group(public, 0);
	if (!ret)
		ret = create_thread_group(public, 1);
	i = -1;
	while (!ret && ++i < public->nop)
	 	ret = pthread_join(public->philo[i].thread_id, (void **)&status);
	return (ret);
}
