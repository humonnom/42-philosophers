#include "philo_one.h"

static char
	*get_type_message(int type)
{

	if (type == TYPE_EAT)
		return("is eating\n");
	if (type == TYPE_SLEEP)
		return("is sleeping\n");
	if (type == TYPE_THINK)
		return("is thinking\n");
	if (type == TYPE_FORK)
		return("has taken a fork\n");
	return(NULL);
}

void
	display_message(t_philo *philo, int type)
{
	char		*message;
	int			time;

	pthread_mutex_lock(&philo->rule->write_mutex);
	message = get_type_message(type);
	if (!message)
		return ;
	time = get_time() - philo->rule->start_time;
	//if (type != TYPE_DIED && )
	printf(ANSI_COLOR_RED"%d\t%d %s"ANSI_COLOR_RESET, time, philo->philo_id, message);
	pthread_mutex_unlock(&philo->rule->write_mutex);
}
