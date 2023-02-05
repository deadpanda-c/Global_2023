CXX	=	g++

SRC =	$(shell find src/ -name "*.cpp" ! -name main.cpp -type f)

OBJ = $(SRC:.cpp=.o)

NAME =	game

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

WFLAGS	=	-W -Wall -Wextra -Werror -std=c++20 -g -I includes

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) src/main.cpp $(OBJ) $(WFLAGS) $(SFMLFLAGS)

all:	 $(NAME)

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -rf $(NAME)
	clear

re: 	fclean all
