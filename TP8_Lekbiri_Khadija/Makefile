# Variables
CC = g++
CFLAGS = -std=c++17
OBJ_FILES = main.o Movie.o Movies.o

# Cible par défaut
all: whole

# Création de l'exécutable
whole: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o whole $(OBJ_FILES)

# Compilation des fichiers objets
main.o: main.cpp Movie.hpp Movies.hpp
	$(CC) $(CFLAGS) -c main.cpp

Movie.o: Movie.cpp Movie.hpp
	$(CC) $(CFLAGS) -c Movie.cpp

Movies.o: Movies.cpp Movies.hpp Movie.hpp
	$(CC) $(CFLAGS) -c Movies.cpp

# Commande de nettoyage
clean:
	del /f /q *.o whole.exe
