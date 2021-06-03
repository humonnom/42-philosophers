#include "philo_one.h"

int
	act_sleep(t_philo *philo)
{
	int ret;

	ret = display_message(philo, TYPE_SLEEP);
	if (!ret)
		usleep(1000 * philo->rule->time_to_sleep);
	return (ret);
}
