##
## Makefile for Makefile in /home/bloubtek/projets/philo
## 
## Made by morgane ferrandis
## Login   <bloubtek@epitech.net>
## 
## Started on  Tue Mar 18 15:25:42 2014 morgane ferrandis
## Last update Tue Mar 18 15:39:13 2014 morgane ferrandis
##

NAME		=

SRC		=

OBJ		=

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all