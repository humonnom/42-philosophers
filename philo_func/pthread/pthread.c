#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

void	print_index_loop(char *str, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		printf("[%s]i is %d\n", str, i);
		usleep(1000 * 100);
		++i;
	}
}

void	*thread_routine(void *arg)
{
	print_index_loop("thread", 5);
	while(1)
		;
	return (NULL);
}

int 	main()
{
	pthread_t	tid;
	int			create_res;
	int			detach_res;
	int			join_res;

	// [ 1. create new thread in this process ]
	// args:	1.thread(ID)
	//			2.attr(info of new thread, generally filled with NULL)
	//			3.function ptr
	//			4.function's argument
	//			success -> return: 0	// fail -> return: errno
	create_res = pthread_create(&tid, NULL, thread_routine, NULL);
	if (create_res != 0)
		return (1);
	print_index_loop("main", 3);

	// [ 2. detach thread from main thread ]
	// 			success -> return: 0	// fail -> return: errno
	detach_res = pthread_detach(tid);
	printf("detached result: %d\n", detach_res);

	// [ 3. (join)wait for thread ]
	// args:	1. thread(ID)
	//			2.thread function's return value
	join_res = pthread_join(tid, NULL);
	printf("joined result: %d\n", join_res);
	
	return (0);
}
