#include "philo_one.h"

static int
	watch_done(t_philo *philo)
{
	if (!philo->rule->number_of_eat)
		return (0);
	if (!philo->eat_left)
	{
		philo->rule->status[philo->philo_id] = TYPE_DONE;
		philo->rule->state = TYPE_DONE;
		return (1);
	}
	return (0);
}

static int
	watch_died(t_philo *philo)
{
	uint64_t	now;

	now = get_time();
	if (now + philo->rule->time_to_eat > \
		philo->eat_start + philo->rule->time_to_die)
	{
		philo->rule->status[philo->philo_id] = TYPE_DIED;
		philo->rule->state = TYPE_DIED;
		return (1);
	}
	return (0);
}

void
	*watch_died_or_done(void *arg)
{
	t_philo	*philo;
	int		ret;

	philo = (t_philo *)arg;
	ret = 0;
	while (1)
	{
		//pthread_mutex_lock(&philo->rule->watch_mutex);
		if (watch_died(philo))
		{
			display_message(philo, TYPE_DIED);
			ret = 1;
		}
		if (watch_done(philo))
			ret = 1;
		//pthread_mutex_unlock(&philo->rule->watch_mutex);
		if (ret)
			return ((void *)1);

	}
	return ((void *)1);
}
