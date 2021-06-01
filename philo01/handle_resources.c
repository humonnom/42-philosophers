#include "philo_one.h"

int
	handle_resources(t_philo *philos, int number_of_philos)
{
	int i;

	i = -1;
	while (++i < number_of_philos)
	{
		free(philos[i].forks);
	}
	free(philos);
	return (0);
}
