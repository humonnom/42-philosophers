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
	if (type == TYPE_DIED)
		return("is died\n");
	return("there is no message to print out\n");
}

static void
	handle_text_color(int type)
{
	if (type == TYPE_RESET_COLOR)
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

static void
	print_out_message(t_rule *rule, int type, int philo_id)
{
	int			time;
	char		*message;

	message = get_type_message(type);
	time = get_time() - rule->start_time;
	handle_text_color(type);
	printf("%d\t%d %s", time, philo_id, message);
	handle_text_color(TYPE_RESET_COLOR);
}

static int
	is_invalid_print(t_rule *rule, t_philo *philo, int type)
{
	if (rule->print == NON_PRINT)
		return (1);
	if (rule->status[philo->philo_id] == TYPE_DONE)
		return (1);
	if (type != TYPE_DIED && rule->state == TYPE_DIED)
		return (1);
	return (0);
}

int
	display_message(t_philo *philo, int type)
{
	int			ret;
	t_rule		*rule;

	rule = call_rule();
	pthread_mutex_lock(&rule->write_mutex);
	ret = is_invalid_print(rule, philo, type);
	if (!ret)
		print_out_message(rule, type,philo->philo_id);
	if (type == TYPE_DIED)
	{
		rule->print = NON_PRINT;
		ret = 1;
	}
	pthread_mutex_unlock(&rule->write_mutex);
	return (ret);
}
