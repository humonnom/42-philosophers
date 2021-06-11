#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"

//structure
typedef struct			s_philo
{
	pthread_mutex_t		mutex;
	pthread_t			thread;
	pthread_t			watcher;
	uint64_t			eat_start;
	uint64_t			time_left;
	int					id;
	int					right_fork;
	int					left_fork;
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

//macro

# define INVALID_ARGC 1
# define INVALID_RULE 2
# define FAIL_MALLOC 3
# define INVALID_EAT_NUM 4

# define INVALID_PHILOS_NUM 200
# define INVALID_TIME_SET 60

# define UNDECIDED_NOE 0
# define ARG_NUM_WITHOUT_NOE 5
# define ARG_NUM_WITH_NOE 6

# define TYPE_NONE 0
# define TYPE_EAT 1
# define TYPE_SLEEP 2
# define TYPE_THINK 3
# define TYPE_DIED 5
# define TYPE_DONE 6
# define TYPE_FORK 4
# define TYPE_EXIT 7

# define PRINT 1
# define NON_PRINT 2

# define TYPE_RESET_COLOR 11
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"
//functions

t_rule
	*call_rule(void);


int
	gen_philos(t_rule *rule);

int
	set_rule(
				t_rule *rule,
				char **rule_str,
				int arg_num);
int
	is_invalid_rule(t_rule *rule);

int
	is_invalid_arg_num(int argc);

int
	exit_program(void);

uint64_t
	get_time(void);


int
	handle_thread(t_rule *rule);


void
	*philo_routine(void *arg);

int
	act_eat(t_philo *philo);

int
	act_sleep(t_philo *philo);

int
	act_think(t_philo *philo);

void
	display_err_message(int err_number);

int
	display_message(t_philo *philo, int type);

int
	watch_done(t_philo *philo);

void
	*watch_died(void *arg);

int
	usleep_loop(int ms);

#endif
