CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS	= rcs
RM = rm -f
NAME = libft.a

FUNCS = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd 
FUNCS_B = ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap

SRCS = $(addsuffix .c, $(FUNCS))
SRCS_B = $(addsuffix .c, $(FUNCS_B))
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

bonus: $(NAME) $(OBJS_B)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS_B)

all : bonus

clean :
	@$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: bonus all clean fclean re
