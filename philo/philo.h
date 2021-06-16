/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:53:17 by juepark           #+#    #+#             */
/*   Updated: 2021/06/16 20:31:21 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include<errno.h>

/*
** structure
*/

typedef struct			s_philo
{
	pthread_t			thread_id;
	pthread_t			watcher;
	uint64_t			eat_start;
	int					id;
	int					eat_left;
	int					hands;
	int					left_fork;
	int					right_fork;
}						t_philo;

typedef struct			s_public
{
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		state_mutex;
	pthread_mutex_t		*forks;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	uint64_t			start_time;
	int					nop;
	int					number_of_eat;
	int					*status;
	int					state;
	int					print_flag;
	int					errcode;
	t_philo				*philo;
}						t_public;

/*
** macro
*/

# define INVALID_ARGC 1
# define INVALID_RULE 2
# define FAIL_MALLOC 3
# define INVALID_EAT_NUM 4

# define INVALID_PHILOS_NUM 200
# define INVALID_TIME_SET 60

# define UNDECIDED_NOE 0
# define ARG_NUM_WITHOUT_NOE 5
# define ARG_NUM_WITH_NOE 6

/*
** state & status[i]
*/

# define TYPE_INIT 0
# define TYPE_EAT 1
# define TYPE_SLEEP 2
# define TYPE_THINK 3
# define TYPE_DIED 4
# define TYPE_DONE 5
# define TYPE_EXIT 6
# define TYPE_GRAB 7

/*
** hands
*/

# define HANDS_TYPE_EMPTY 0
# define HANDS_TYPE_FULL 1

# define TYPE_PRINT_VALID 1
# define TYPE_PRINT_INVALID 2

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

/*
**functions
*/

int
	gen_philos(t_public *public);

t_public
	*call_public(void);

int
	set_public(
				t_public *public,
				char **public_str,
				int arg_num);

int
	is_invalid_rule(t_public *public);

int
	is_invalid_argc(int argc);

int
	garbage_collector(void);

uint64_t
	get_time(void);

int
	handle_thread(t_public *public);


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

/*
** utils
*/

int
	ft_atoi(const char *nptr);

int
	ft_isdigit(int c);

#endif
