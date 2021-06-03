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

static int
	is_invalid_print(t_philo *philo, int type)
{
	if (type != TYPE_DIED && philo->rule->state == TYPE_DIED)
		return (1);
	return (0);
}

int
	display_message(t_philo *philo, int type)
{
	char		*message;
	int			time;

	pthread_mutex_lock(&philo->rule->write_mutex);
	if (is_invalid_print(philo, type))
		return (1);
	message = get_type_message(type);
	if (!message)
	{
		printf("display_message: unkown type error\n");
		return (0);
	}
	time = get_time() - philo->rule->start_time;
	printf(ANSI_COLOR_RED"%d\t%d %s"ANSI_COLOR_RESET, time, philo->philo_id, message);
	pthread_mutex_unlock(&philo->rule->write_mutex);
	return (0);
}
