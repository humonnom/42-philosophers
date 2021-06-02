#include "philo_one.h"

int
	handle_resources(t_philo *philos)
{
	int i;

	i = -1;
	while (++i < philos->rule->number_of_philos)
		pthread_mutex_destroy(&philos->rule->forks[i]);
	pthread_mutex_destroy(&philos->rule->write_mutex);
	pthread_mutex_destroy(&philos->rule->check_fork_mutex);
	free(philos->rule->forks);
	free(philos);
	return (0);
}
