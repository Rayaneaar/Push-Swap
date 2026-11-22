.PHONY: all clean
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
# To change later
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all

