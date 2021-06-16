#include "philo.h"

static void
	destroy_mutex(pthread_mutex_t mutex)
{
	int ret;

	ret = pthread_mutex_destroy(&mutex);
	if (ret == EBUSY)
	{
		pthread_mutex_unlock(&mutex);
		ret = pthread_mutex_destroy(&mutex);
	}
}

static void
	destroy_all_mutexs(t_public *public)
{
	int i;

	i = -1;
	while (++i < public->nop)
		destroy_mutex(public->forks[i]);
	destroy_mutex(public->state_mutex);
	destroy_mutex(public->write_mutex);
}

int
	garbage_collector()
{
	t_public	*public;

	public = call_public();
	destroy_all_mutexs(public);
	if (public->status)
		free(public->status);
	if (public->forks)
		free(public->forks);
	if (public->philo)
		free(public->philo);
	return (1);
}

