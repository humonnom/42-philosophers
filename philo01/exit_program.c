#include "philo_one.h"

int
	exit_program()
{
	printf("exit_program\n");
	#if 0
	//printf("PROGRAM OVER :from %d\n", philo->id);
	printf("philo->rule->errcode:%d\n",philo->rule->errcode);
	if (philo->rule->errcode)
		display_err_message(philo->rule->errcode);
	// if (philo->rule->state == TYPE_DIED)
	#endif
	return (1);
}

