#-*-Makefile-*-

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCM =  ft_printf.c ft_printf_utils.c
OBJM = $(SRCM:%.c=%.o)
NAME = libftprintf.a
HEADER = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJM) 
	ar rcs $@ $^

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $<

clean :
	rm -f $(OBJM) 
fclean : clean
	rm -f $(NAME)

re : fclean all
