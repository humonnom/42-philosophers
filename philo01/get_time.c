#include "philo_one.h"

uint64_t
	get_time(void)
{
	struct timeval time_info;

	gettimeofday(&time_info, NULL);
	//printf("sec: {%ld}\n", time_info.tv_sec);
	// printf("{%ld}\n", time_info.tv_sec * 1000);
	// printf("{%llu}\n", time_info.tv_sec * (uint64_t)1000);
	//printf("usec: {%ld}\n", time_info.tv_usec);
	return (time_info.tv_sec * 1000 + time_info.tv_usec/1000);
}
