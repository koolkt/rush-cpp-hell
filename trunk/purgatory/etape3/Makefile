##
## Makefile for Makefile in /home/beauvo_m/Epitech/Projets/Piscine/day06/ex00
## 
## Made by maxime beauvois
## Login   <beauvo_m@epitech.net>
## 
## Started on  Mon Jan  9 12:07:06 2012 maxime beauvois
## Last update Tue Jun 26 17:43:01 2012 Florian.Noirbent
##

NAME	=	test_dynamic_fsa

SRCS	=	Edge.cpp    \
		State.cpp   \
		FSA.cpp     \
		Matcher.cpp \
		main.cpp

CFLAGS	=	-W -Wall -g

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

LIB	=	

CC	=	g++

$(NAME)	: 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB)

all	:	$(NAME)

%.o	:	%.cpp
		$(CC) -o $(CFLAGS) -o $@ -c $<

clean	:
		@$(RM) $(OBJS)

fclean	:	clean
		@$(RM) $(NAME)

re	:	fclean all
