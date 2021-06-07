#include "philo_one.h"

int
	act_sleep(t_philo *philo)
{
	if (display_message(philo, TYPE_SLEEP))
		return (1);
	usleep(1000 * philo->rule->time_to_sleep);
	return (0);
}
