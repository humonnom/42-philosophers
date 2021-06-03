#include "philo_one.h"

void
	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rule->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->rule->forks[philo->left_fork]);
	philo->hands = TYPE_NONE;
	return ;
}
