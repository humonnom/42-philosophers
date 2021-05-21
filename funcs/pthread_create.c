#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	print_index_loop(char *str, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		printf("[%s]i is %d\n", str, i);
		usleep(1000 * 1000);
		++i;
	}
}

void	*thread_routine(void *arg)
{
	print_index_loop("thread", 10);
	return (NULL);
}

int 	main()
{
	pthread_t	thread;
	int			create_res;
	
	// [ create new thread in this process ]
		// args: 1.thread(ID) 2.attr(info of new thread, generally filled with NULL) 3.function ptr 4.function's argument
	create_res = pthread_create(&thread, NULL, thread_routine, NULL);	
		// success -> return: 0	// fail -> return: error 
	if (create_res)
		return (1);
	print_index_loop("main", 5);

	// [ wait for thread ]
		// args: 1. thread(ID) 2.thread function's return value
	pthread_join(thread, NULL);

	// [  ]
	return (0);
}
