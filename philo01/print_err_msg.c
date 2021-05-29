#include "philo_one.h"

void
	print_err_msg(int err_number)
{
	if (err_number == INVALID_ARGC)
		printf("[ Invalid argc ]\n");
	else if (err_number == INVALID_EAT_NUM)
		printf("[ Invalid eat number ]\n");
	else if (err_number == INVALID_PHILOS_NUM)
		printf("[ Invalid philos number(more than 200) ]\n");
	else if (err_number == INVALID_TIME_SET)
		printf("[ Invalid time set(over 60ms) ]\n");
	else if (err_number == INVALID_RULE)
		printf("[ Invalid rule ]\n");
	else
		printf("[ Unspecified error occurred ]\n");
}