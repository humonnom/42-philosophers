NAME		= philo_one

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
SRCS		=	main.c \
				set_rule.c \
				is_invalid.c \
				gen_philos.c \
				exit_program.c \
				get_time.c \
				handle_thread.c \
				philo_routine.c \
				act_eat.c \
				act_sleep.c \
				act_think.c \
				display_message.c \
				display_err_message.c \
				watch_done.c \
				watch_died.c \
				# \

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIR		= ./objs
LIBDIR		= ./libft
LIBFT		= -L./libft -lft

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBDIR) all
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS) -lpthread

$(OBJDIR)/%.o:%.c
			@mkdir $(OBJDIR) 2> /dev/null || true
			$(CC) $(CFLAGS) -I./philo_one.h -o $@ -c $<

clean:
			@rm -rf $(OBJDIR) 2> /dev/null || true
			@$(MAKE) -C $(LIBDIR) clean

fclean:		clean
			@rm -rf $(NAME) 2> /dev/null || true
			@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all

simple:		re
			@./$(NAME) 8 410 100 100 1

test:		re
			@./$(NAME) 4 410 200 200
			# "no one should die"

test2:		re
			@./$(NAME) 4 310 200 100
			# "a philosopher should die"

test3:		re
			@./$(NAME) 5 800 200 200
			# "no one should die"

noe:		re
			@./$(NAME) 5 800 200 200 7
			# "no one should die"

err:		re
			@./$(NAME) 4 200 200 200 -5

.PHONY:		all clean fclean re simple test test2 test3 noe err
