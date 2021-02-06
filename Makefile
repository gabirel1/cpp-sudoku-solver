SRC =	main.cpp				\
		sudokuBoard.cpp			\

CC = g++

NAME = sudoku_solver

OBJ = $(SRC:.cpp=.o)

CPPFLAGS	=	-W -Wall -Wextra

all : $(NAME)

$(NAME) :	$(OBJ)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(NAME)

re :	fclean all