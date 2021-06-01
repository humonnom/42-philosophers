#include "philo_one.h"

void
	*watch_count(void *arg)
{
	t_rule	*rule;
	int		i;
	int		j;

	rule = (t_rule *)arg;
	while (j < rule->number_of_eat)
	{
		i = 0;
		while (i < rule->number_of_philos)
		{
			i++;
		}
		j++;
	}
	//printf("[%d]\n", philo->philo_id);
	//pthread_mutex_lock(&philo->mutex);
	//pthread_mutex_unlock(&philo->mutex);
	return (0);
}
