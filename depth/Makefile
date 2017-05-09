NAME	= solver

SRC	= src/main.c \
	  src/my_fonc1.c \
	  src/get_next_line.c \
	  src/init_char.c \
	  src/init_node.c \
	  src/display_fonc.c

OBJ	=$(SRC:.c=.o)

ifeq ($(DEBUG),1)
CFLAGS	+= -g3
endif

CFLAGS	+= -W -Wall -Wextra -O2 -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
