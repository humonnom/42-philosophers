#include "philo.h"

static int
	create_thread_group(t_rule *rule, int from)
{
	int		ret;
	void	*arg;
	int		i;

	ret = 0;
	i = from;
	while (!ret && i < rule->number_of_philos)
	{
		arg = &(rule->philo[i]);
		ret = pthread_create(&rule->philo[i].thread, NULL, &philo_routine, arg);
		if (!ret && i == 0)
			usleep(100);
		i += 2;
	}
	return (ret);
}

int
	handle_thread(t_rule *rule)
{
	int		i;
	int		ret;
	int		status;

	ret = create_thread_group(rule, 0);
	if (!ret)
		ret = create_thread_group(rule, 1);
	i = -1;
	while (!ret && ++i < rule->number_of_philos)
	 	ret = pthread_join(rule->philo[i].thread, (void **)&status);
	return (ret);
}
