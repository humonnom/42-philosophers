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
	if (rule->number_of_philo < 2)
		return (1);
	if (rule->number_of_philo > 200)
		return (1);
	if (rule->time_to_eat < 60)
		return (1);
	if (rule->time_to_sleep < 60)
		return (1);
	if (rule->time_to_die < 60)
		return (1);
	if (rule->number_of_eat < 0)
		return (1);
	return (0);
}