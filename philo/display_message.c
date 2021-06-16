#include "philo.h"

static char
	*get_type_message(int type)
{

	if (type == TYPE_EAT)
		return("is eating\n");
	if (type == TYPE_SLEEP)
		return("is sleeping\n");
	if (type == TYPE_THINK)
		return("is thinking\n");
	if (type == TYPE_GRAB)
		return("has taken a fork\n");
	if (type == TYPE_DIED)
		return("is died\n");
	return("UNDEFINED MESSAGE...\n");
}

static int
	handle_text_color(int type)
{
	if (type == TYPE_DIED)
		printf(ANSI_COLOR_RED);
	else if (type == TYPE_EAT)
		printf(ANSI_COLOR_YELLOW);
	else if (type == TYPE_SLEEP)
		printf(ANSI_COLOR_CYAN);
	else if (type == TYPE_THINK)
		printf(ANSI_COLOR_BLUE);
	else
		return (0);
	return (1);
}

static void
	print_out_message(t_public *public, int type, int id)
{
	int			time;
	char		*message;
	int			color_set;

	message = get_type_message(type);
	time = get_time() - public->start_time;
	color_set = handle_text_color(type);
	printf("%d\t%d %s", time, id, message);
	if (color_set)
		printf(ANSI_COLOR_RESET);
}

static int
	is_invalid_print(t_public *public, t_philo *philo, int type)
{
	if (public->print_flag == TYPE_PRINT_INVALID)
		return (1);
	if (public->status[philo->id] == TYPE_DONE)
		return (1);
	if (type != TYPE_DIED && public->state == TYPE_DIED)
		return (1);
	return (0);
}

int
	display_message(t_philo *philo, int type)
{
	int			ret;
	t_public		*public;

	public = call_public();
	ret = is_invalid_print(public, philo, type);
	if (!ret)
	{
		pthread_mutex_lock(&public->write_mutex);
		print_out_message(public, type,philo->id);
		pthread_mutex_unlock(&public->write_mutex);
	}
	if (type == TYPE_DIED)
	{
		public->print_flag = TYPE_PRINT_INVALID;
		ret = 1;
	}
	return (ret);
}
