#include "philo.h"

int
	is_invalid_argc(int argc)
{
	if (argc == ARG_NUM_WITHOUT_NOE || argc == ARG_NUM_WITH_NOE)
		return (0);
	return (1);
}

int
	is_invalid_rule(t_public *public)
{
	if (public->nop < 2)
		return (INVALID_PHILOS_NUM);
	if (public->nop >= 200)
		return (INVALID_PHILOS_NUM);
	if (public->time_to_eat < 60)
		return (INVALID_TIME_SET);
	if (public->time_to_sleep < 60)
		return (INVALID_TIME_SET);
	if (public->time_to_die < 60)
		return (INVALID_TIME_SET);
	if (public->number_of_eat < 0)
		return (INVALID_EAT_NUM);
	return (0);
}
