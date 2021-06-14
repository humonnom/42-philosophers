#include <sys/time.h>
#include <stdio.h>

int main()
{
	struct timeval time_info;

	gettimeofday(&time_info, NULL);
	printf("time is %ld seconds\n", time_info.tv_sec);
	return (0);
}
