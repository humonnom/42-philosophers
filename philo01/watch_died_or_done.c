#include "philo_one.h"

static void
	watch_done(t_philo *philo)
{
	if (!philo->rule->number_of_eat)
		return ;
	if (!philo->eat_left)
		philo->rule->status[philo->philo_id] = TYPE_DONE;
}

static void
	watch_died(t_philo *philo)
{
	uint64_t	now;

	now = get_time();
	if (now + philo->rule->time_to_eat > \
		philo->eat_start + philo->rule->time_to_die)
		philo->rule->status[philo->philo_id] = TYPE_DIED;
}

void
	watch_died_or_done(t_info *info)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < info->rule.number_of_philos)
		{
			watch_died(&info->philo[i]);
			watch_done(&info->philo[i]);
		}
	}
}
