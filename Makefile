##
## Makefile for Makefile in /home/bloubtek/projets/philo
## 
## Made by morgane ferrandis
## Login   <bloubtek@epitech.net>
## 
## Started on  Tue Mar 18 15:25:42 2014 morgane ferrandis
## Last update Wed Mar 19 16:51:45 2014 severine roy
##

NAME		= philo

SRC		= main.c \
		  actions.c

OBJ		= $(SRC:.c=.o)

CFLAGS		= -pthread -Wall -Wextra -W

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
