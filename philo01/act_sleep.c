#include "philo_one.h"

int
	act_sleep(t_philo *philo)
{
	t_rule	*rule;

	rule = call_rule();
	if (display_message(philo, TYPE_SLEEP))
		return (1);
	usleep_loop(rule->time_to_sleep);
	return (0);
}
