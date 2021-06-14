#include "philo.h"

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
		sem_wait(rule->state_sem);
		rule->state = TYPE_DIED;
		display_message(philo, TYPE_DIED);
		sem_post(rule->state_sem);
	}
	return ((void *)0);
}
