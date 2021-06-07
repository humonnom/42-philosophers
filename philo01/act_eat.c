#include "philo_one.h"

int
	act_eat(t_philo *philo)
{
	philo->rule->status[philo->philo_id] = TYPE_EAT;
	philo->eat_left--;
	philo->eat_start = get_time();
	if (display_message(philo, TYPE_EAT))
		return (1);
	usleep(1000 * philo->rule->time_to_eat);
	if (philo->rule->state == TYPE_DIED)
		return (1);
	philo->rule->status[philo->philo_id] = TYPE_NONE;
	return (0);
}
