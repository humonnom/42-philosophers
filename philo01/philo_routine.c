#include "philo_one.h"
void
	*philo_routine(void *arg)
{
	t_philo 	*philo;
	t_rule		*rule;

	rule = call_rule();
	philo = (t_philo *)arg;
	while (1)
	{

		if (watch_done(philo))
			return ((void *)1);
		if (act_eat(philo))
			return ((void *)1);
		if (act_sleep(philo))
			return ((void *)1);
		if (act_think(philo))
			return ((void *)1);
	}
	return (0);
}
