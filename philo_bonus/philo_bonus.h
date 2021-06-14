#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

#if 0
//structure
typedef struct			s_philo
{
	pthread_mutex_t		mutex;
	pthread_t			thread;
	pthread_t			watcher;
	uint64_t			eat_start;
	uint64_t			time_left;
	int					id;
	int					eat_left;
	int					hands;
}						t_philo;

typedef struct			s_rule
{
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		state_mutex;
	pthread_mutex_t		check_fork_mutex;
	pthread_mutex_t		usleep_mutex;
	pthread_mutex_t		*forks;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	uint64_t			start_time;
	int					number_of_philos;
	int					number_of_eat;
	int					*status;
	int					state;
	int					print;
	int					errcode;
	t_philo				*philo;
}						t_rule;
#endif

typedef struct			s_rule
{
	sem_t				*forks;
}						t_rule;

t_rule
	*call_rule(void);

int
    do_something(int i);
	
# endif