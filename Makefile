SRC = get_next_line_bonus.c \
	  get_next_line_utils_bonus.c \
	  main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = how_to_use_get_next_line
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	-@$(RM) $(OBJ)

fclean: clean
	-@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re