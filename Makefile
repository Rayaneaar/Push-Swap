NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

#TODO : TO REMOVE LATER
SRCS = $(wildcard src/*.c src/*/*.c)
#TODO: TO REMOVE LATER
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(LIBFT_DIR)/ft_printf/include
LIBFT_HEADERS = $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/ft_printf/include/ft_printf.h
HEADERS = $(LIBFT_HEADERS) include/push_swap.h

all: $(NAME)

$(LIBFT): $(LIBFT_HEADERS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean : 
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean 

fclean : clean 
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean 


re : fclean all

.PHONY: all clean fclean re
