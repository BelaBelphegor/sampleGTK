NAME				= sample
SRCS				= main.c
SRCSPATH			= ./srcs/
INCLUDES			= ./includes
CC					= clang
CFLAGS				= -Wall -Werror -Wextra -O3 -g
LFLAGS				= -L ./libft/ -lft
INCLUDES_O			= -I $(INCLUDES) -I ./libft/includes `pkg-config --cflags gtk+-3.0`
INCLUDES_C			= $(LFLAGS) `pkg-config --libs gtk+-3.0`
SRC					= $(addprefix $(SRCSPATH), $(SRCS))
OBJS				= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C	./libft
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(INCLUDES_C) 

%.o: %.c
	$(CC) -o $@ $(INCLUDES_O) $(CFLAGS) $(SDL_HEADER) -c $<

clean:
	make -C ./libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
