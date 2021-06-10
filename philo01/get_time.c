#include "philo_one.h"

uint64_t
	get_time(void)
{
	struct timeval time_info;

	gettimeofday(&time_info, NULL);
	return (time_info.tv_sec * 1000 + time_info.tv_usec/1000);
}
