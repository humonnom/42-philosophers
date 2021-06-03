#include "philo_one.h"

int
	act_eat(t_philo *philo)
{
	int ret;

	ret = 0;
	philo->rule->status[philo->philo_id] = TYPE_EAT;
	philo->eat_left--;
	philo->eat_start = get_time();
	ret = display_message(philo, TYPE_EAT);
	if (!ret)
	{
		//printf("time to eat: %d\n", philo->rule->time_to_eat);
		//printf("[%llu]\n", get_time());
		usleep(1000 * philo->rule->time_to_eat);
		//printf("[%llu]\n", get_time());
		philo->rule->status[philo->philo_id] = TYPE_NONE;
	}
	return (ret);
}
