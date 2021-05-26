#include "philo_one.h"

void
	print_err_msg(int err_number)
{
	if (err_number == INVALID_ARGC)
		printf("[ Invalid argc ]\n");
	else
		printf("[ Unspecified error occurred ]\n");
}