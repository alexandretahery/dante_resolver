##
## Makefile for dante in /home/alexandre/rendu/2016/CPE/dante/astar
## 
## Made by Alexandre Tahery
## Login   <alexandre1.tahery@epitech.eu>
## 
## Started on  Fri Apr 28 12:46:51 2017 Alexandre Tahery
## Last update Fri Apr 28 12:57:30 2017 Alexandre Tahery
##

NAME	= solver

SRC	= src_path/main.c \
	  src_path/node_init.c \
	  src_path/init_fonc.c \
	  src_path/a_star.c \
	  src_path/f_little.c \
	  src_getnextline/get_next_line.c \
	  src_my/my_fonc1.c \
	  src_my/display_fonc.c

OBJ	=$(SRC:.c=.o)

CC	= gcc

ifeq ($(DEBUG),1)
CFLAGS	+= -g3
endif

CFLAGS	+= -W -Wall -I./include -lc_graph_prog_full -lm -O2

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
