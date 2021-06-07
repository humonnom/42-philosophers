#include "philo_one.h"
# define PRINT 1
# define EXIT 2

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
	if (type == TYPE_DIED)
		return("is died\n");
	return(NULL);
}
#if 0
static int
	renew_state(t_philo *philo)
{
	int	i;

	i = 0;
	while (++i <= philo->rule->number_of_philos)
	{
		if (philo->rule->status[i] == TYPE_DIED)
			return (TYPE_DIED);
	}
	return (TYPE_NONE);
}
#endif
static int
	is_invalid_print(t_philo *philo, int type)
{
	if (type != TYPE_DIED && philo->rule->state == TYPE_DIED)
		return (1);
	return (0);
}

static void
	handle_text_color(int type)
{
	if (type == TYPE_UNSET_COLOR)
		printf(ANSI_COLOR_RESET);
	else if (type == TYPE_DIED)
		printf(ANSI_COLOR_RED);
	else if (type == TYPE_EAT || type == TYPE_FORK)
		printf(ANSI_COLOR_YELLOW);
	else if (type == TYPE_SLEEP)
		printf(ANSI_COLOR_CYAN);
	else if (type == TYPE_THINK)
		printf(ANSI_COLOR_BLUE);
	return ;
}

// static int
// 	check_died(t_philo *philo)
// {
// 	int	ret;

// 	ret = 0;
// 	pthread_mutex_lock(&philo->rule->write_mutex);
// 	if (philo->rule->status[philo->philo_id] == TYPE_DIED)
// 		ret = 1;
// 	//kill every thread;
// 	//printf(ANSI_COLOR_MAGENTA"kill every thread\n"ANSI_COLOR_RESET);
// 	pthread_mutex_unlock(&philo->rule->write_mutex);
// 	return (ret);
// }

int
	display_message(t_philo *philo, int type)
{
	char		*message;
	int			time;

	pthread_mutex_lock(&philo->rule->write_mutex);
	if (is_invalid_print(philo, type))
	{
		printf("invalid print: %d, %d\n", philo->philo_id, type);
		return (1);
	}
	message = get_type_message(type);
	if (!message)
	{
		printf("display_message: unkown type error\n");
		return (1);
	}
	time = get_time() - philo->rule->start_time;
	handle_text_color(type);
	printf("%d\t%d %s", time, philo->philo_id, message);
	handle_text_color(TYPE_UNSET_COLOR);
	if (type == TYPE_DIED)
		return (1);
	pthread_mutex_unlock(&philo->rule->write_mutex);
	return (0);
}
