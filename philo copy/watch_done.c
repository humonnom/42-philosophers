#include "philo.h"

int
	watch_done(t_philo *philo)
{
	t_rule	*rule;

	rule = call_rule();
	if (rule->number_of_eat == UNDECIDED_NOE)
		return (0);
	if (philo->eat_left <= 0)
	{
		pthread_mutex_lock(&rule->state_mutex);
		rule->status[philo->id] = TYPE_DONE;
		pthread_mutex_unlock(&rule->state_mutex);
		return (1);
	}
	return (0);
}
