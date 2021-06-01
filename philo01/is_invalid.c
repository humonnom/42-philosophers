#include "philo_one.h"

int
	is_invalid_arg_num(int argc)
{
	if (argc == UNDECIDED_EAT_NUM || argc == DECICED_EAT_NUM)
		return (0);
	return (1);
}

int
	is_invalid_rule(t_rule *rule)
{
	if (rule->number_of_philos < 2)
		return (INVALID_PHILOS_NUM);
	if (rule->number_of_philos > 200)
		return (INVALID_PHILOS_NUM);
	if (rule->time_to_eat < 60)
		return (INVALID_TIME_SET);
	if (rule->time_to_sleep < 60)
		return (INVALID_TIME_SET);
	if (rule->time_to_die < 60)
		return (INVALID_TIME_SET);
	if (rule->number_of_eat < 0)
		return (INVALID_EAT_NUM);
	return (0);
}
