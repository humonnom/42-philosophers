#include "philo_one.h"

void
	act_sleep(t_philo *philo)
{
	display_message(philo, TYPE_SLEEP);
	usleep(1000 * philo->rule->time_to_sleep);
	return ;
}
