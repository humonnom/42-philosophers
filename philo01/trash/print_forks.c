#include "philo_one.h"

void
	print_forks(t_philo *philo)
{
	int id;

	pthread_mutex_lock(&philo->rule->write_mutex);
	id = philo->philo_id;
	printf("[%d] ->\t", id);
	//int i = -1;
	// while(++i < philo->rule->number_of_philos)
	// 	printf("[%d] ", philo->rule->forks_locked[i]);
	printf("\n");
	pthread_mutex_unlock(&philo->rule->write_mutex);
}
