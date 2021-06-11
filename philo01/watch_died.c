#include "philo_one.h"

void
	*watch_died(void *arg)
{
	t_rule	*rule;
	t_philo	*philo;
	int		eat_left_old;

	philo = (t_philo *)arg;
	rule = call_rule();
	eat_left_old = philo->eat_left;
	usleep_loop(rule->time_to_die);
	if (rule->status[philo->id] != TYPE_DONE && eat_left_old == philo->eat_left)
	{
		rule->status[philo->id] = TYPE_DIED;
		pthread_mutex_lock(&rule->state_mutex);
		rule->state = TYPE_DIED;
		display_message(philo, TYPE_DIED);
		pthread_mutex_unlock(&rule->state_mutex);
	}
	return ((void *)0);
}
