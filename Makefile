##
## Makefile for Makefile in /home/bechad_p/rendu/PSU_2014_lemipc
## 
## Made by Pierre Bechade
## Login   <bechad_p@epitech.net>
## 
## Started on  Thu Feb 26 16:49:00 2015 Pierre Bechade
## Last update Sun Mar  8 18:38:02 2015 Pierre Bechade
##

CC	=	gcc

NAME	=	lemipc

CFLAGS	=	-W -Wall -Werror -Wextra -lpthread -I./include/ -g3

SRC	=	src/lemipc.c		\
		src/handle_error.c	\
		src/algo.c		\
		src/check.c		\
		src/arena.c

RM	=	rm -f

OBJS	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean clean all
