##
## Makefile for dante in /home/alexandre/rendu/2016/CPE/dante/breadth
## 
## Made by Alexandre Tahery
## Login   <alexandre1.tahery@epitech.eu>
## 
## Started on  Fri Apr 28 13:07:07 2017 Alexandre Tahery
## Last update Fri Apr 28 13:07:28 2017 Alexandre Tahery
##

NAME	= solver

SRC	= src/main.c \
	  src/my_fonc1.c \
	  src/get_next_line.c \
	  src/init_char.c \
	  src/init_node.c \
	  src/display_fonc.c \
	  src/fonc_list.c

OBJ	=$(SRC:.c=.o)

ifeq ($(DEBUG),1)
CFLAGS	+= -g3
endif

CFLAGS	+= -W -Wall -Wextra -I./include -O2

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
