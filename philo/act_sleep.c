#include "philo.h"

int
	act_sleep(t_philo *philo)
{
	t_public	*public;

	public = call_public();
	if (display_message(philo, TYPE_SLEEP))
		return (1);
	usleep_loop(public->time_to_sleep);
	return (0);
}
