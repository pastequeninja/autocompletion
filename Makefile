##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.cpp				\
		src/Parser.cpp				\
		src/autoCompletion.cpp		\
		Errors/Errors.cpp			\
		Errors/InvalidArguments.cpp	\
		Errors/UnkownAdress.cpp		\


SRC_TEST	=	tests/testParser.c			\

NAMETEST = unit_tests

NAME	=	autoCompletion

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I ./include -I ./Errors -W -Wextra -Wall -Werror -g

TESTFLAGS = -lcriterion -lgcov --coverage

CC	=	g++

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

clean:
		$(RM) $(OBJ)
		$(RM) *.gc*

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(NAMETEST)

re:		fclean all

tests_run: 	clean
		$(CC) -o $(NAMETEST) $(SRC_TEST) $(CXXFLAGS) $(TESTFLAGS)
		./$(NAMETEST)
		gcovr --exclude tests

debug:	CXXFLAGS += -g
debug:	re
