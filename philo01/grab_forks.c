#include "philo_one.h"

void
	grab_forks(t_philo *philo)
{
	if (philo->philo_id % 2)
	{
		pthread_mutex_lock(&philo->rule->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->rule->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->rule->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->rule->forks[philo->right_fork]);
	}
	display_message(philo, TYPE_FORK);
	display_message(philo, TYPE_FORK);
	return ;
}
