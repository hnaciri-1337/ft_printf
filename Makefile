SRCS = ft_printf.c ft_putbases.c ft_putnbr.c
CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)
all : $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
