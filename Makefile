NAME = get_next_line.a

# Archivos fuente
SRCS = get_next_line_utils.c\

FLAGS = -Wall -Wextra -Werror

CC = cc

CLEAN = rm -rf

# CLEAN = del /Q /F

OBJ := $(SRCS:.c=.o)

OBJ_BONUS := $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(OBJ): $(SRCS)
	$(CC) -g $(FLAGS) -c $(SRCS)

$(NAME): $(OBJ)
	ar -rsc $(NAME) $(OBJ)

$(OBJ_BONUS): %.o: %.c
	$(CC) $(FLAGS) -c $(SRCS_BONUS)

clean:
	@$(CLEAN) *.o

fclean: clean
	@$(CLEAN) *.a

re: fclean all

.PHONY: all clean fclean re bonus
