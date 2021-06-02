#include "philo_one.h"

void
	grab_forks(t_philo *philo)
{
	// printf("try to grab a fork: pid=%d, left_fork: %d\n", philo->philo_id, philo->right_fork);
	// printf("try to grab a fork: pid=%d, left_fork: %d\n",philo->philo_id ,philo->left_fork);
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
	// printf("**grab a fork: pid=%d, right_fork: %d\n",philo->philo_id ,philo->right_fork);
	// printf("**grab a fork: pid=%d, left_fork: %d\n",philo->philo_id ,philo->left_fork);
	display_message(philo, TYPE_FORK);
	display_message(philo, TYPE_FORK);
	return ;
}
