#include "philo.h"

int
	watch_done(t_philo *philo)
{
	t_public	*public;

	public = call_public();
	if (public->number_of_eat == UNDECIDED_NOE)
		return (0);
	if (philo->eat_left <= 0)
	{
		pthread_mutex_lock(&public->state_mutex);
		public->status[philo->id] = TYPE_DONE;
		pthread_mutex_unlock(&public->state_mutex);
		return (1);
	}
	return (0);
}
