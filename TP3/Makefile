
CXX =		g++

NAME =		tp3

SRC	=	Personne.cpp \
		Annuaire.cpp \
		Adresse.cpp \
		ArbreGenealogique.cpp\
		main.cpp

OBJ	=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
		$(CXX) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		rm $(OBJ)

fclean:		clean
		rm $(NAME)

re:
		fclean all

