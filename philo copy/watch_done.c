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
		sem_wait(rule->state_sem);
		rule->status[philo->id] = TYPE_DONE;
		sem_post(rule->state_sem);
		return (1);
	}
	return (0);
}
