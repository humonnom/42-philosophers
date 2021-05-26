#include "philo_one.h"

int
	is_invalid_arg_num(int argc)
{
	if (argc == UNDECIDED_EAT_NUM || argc == DECICED_EAT_NUM)
		return (0);
	return (1);
}