CC = g++
CFLAGS = -std=c++17
OBJ_FILES = main.o Checking_Account.o Savings_Account.o Trust_Account.o Account_Util.o Account.o

all: my_program

my_program: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o whole $(OBJ_FILES)

main.o: main.cpp Account_Util.hpp
	$(CC) $(CFLAGS) -c main.cpp

Account.o: Account.cpp Account.hpp
	$(CC) $(CFLAGS) -c Account.cpp

Checking_Account.o: Checking_Account.cpp Account.hpp
	$(CC) $(CFLAGS) -c Checking_Account.cpp

Savings_Account.o: Savings_Account.cpp Account.hpp
	$(CC) $(CFLAGS) -c Savings_Account.cpp

Trust_Account.o: Trust_Account.cpp Savings_Account.hpp
	$(CC) $(CFLAGS) -c Trust_Account.cpp

Account_Util.o: Account_Util.cpp Checking_Account.hpp Savings_Account.hpp Trust_Account.hpp
	$(CC) $(CFLAGS) -c Account_Util.cpp

clean:
	del /f /q *.o whole.exe








































# # Variables
# CC = g++
# CFLAGS = -std=c++17
# OBJ_FILES = main.o Movie.o Movies.o

# # Cible par défaut
# all: whole

# # Création de l'exécutable
# whole: $(OBJ_FILES)
# 	$(CC) $(CFLAGS) -o whole $(OBJ_FILES)

# # Compilation des fichiers objets
# main.o: main.cpp Movie.hpp Movies.hpp
# 	$(CC) $(CFLAGS) -c main.cpp

# Movie.o: Movie.cpp Movie.hpp
# 	$(CC) $(CFLAGS) -c Movie.cpp

# Movies.o: Movies.cpp Movies.hpp Movie.hpp
# 	$(CC) $(CFLAGS) -c Movies.cpp

# # Commande de nettoyage
# clean:
# 	del /f /q *.o whole.exe
