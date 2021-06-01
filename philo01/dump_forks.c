#include "philo_one.h"

void
	dump_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->forks[philo->right_fork]);
	return ;
}
