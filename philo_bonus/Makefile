NAME		= philo_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
SRCS		=	main.c \
				call_rule.c \
				do_something.c \
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
			$(CC) $(CFLAGS) -I./philo_bonus.h -o $@ -c $<

clean:
			@rm -rf $(OBJDIR) 2> /dev/null || true
			@$(MAKE) -C $(LIBDIR) clean

fclean:		clean
			@rm -rf $(NAME) 2> /dev/null || true
			@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all


.PHONY:		all clean fclean re 
