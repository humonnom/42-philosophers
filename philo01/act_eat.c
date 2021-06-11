#include "philo_one.h"

static int
	grab_forks(t_rule *rule, t_philo *philo)
{
	pthread_mutex_lock(&rule->forks[philo->left_fork]);
	pthread_mutex_lock(&rule->forks[philo->right_fork]);
	philo->hands = TYPE_FORK;
	if (display_message(philo, TYPE_FORK))
		return (1);
	if (display_message(philo, TYPE_FORK))
		return (1);
	return (0);
}


static void
	release_forks(t_rule *rule, t_philo *philo)
{
	pthread_mutex_unlock(&rule->forks[philo->left_fork]);
	pthread_mutex_unlock(&rule->forks[philo->right_fork]);
	philo->hands = TYPE_NONE;
}


int
	act_eat(t_philo *philo)
{
	t_rule	*rule;

	rule = call_rule();
	if (grab_forks(rule, philo))
		return (1);
	philo->eat_left--;
	philo->eat_start = get_time();
	if (pthread_create(&philo->watcher, NULL, &watch_died, (void *)philo))
		return (1);
	pthread_detach(philo->watcher);
	if (display_message(philo, TYPE_EAT))
		return (1);
	usleep_loop(rule->time_to_eat);
	if (philo->hands == TYPE_FORK)
		release_forks(rule, philo);
	return (0);
}
