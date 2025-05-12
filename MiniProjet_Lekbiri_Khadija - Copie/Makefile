CC = g++
CFLAGS = -std=c++17
OBJ_FILES = main.o Resource.o Container.o Pod.o Server.o CloudExceptions.o KubernetesCluster.o Cloud_Util.o 

all: my_program

my_program: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o whole $(OBJ_FILES)

main.o: main.cpp Cloud_Util.hpp
	$(CC) $(CFLAGS) -c main.cpp

Resource.o: Resource.cpp Resource.hpp
	$(CC) $(CFLAGS) -c Resource.cpp

Container.o: Container.cpp Resource.hpp
	$(CC) $(CFLAGS) -c Container.cpp

Pod.o: Pod.cpp Container.hpp
	$(CC) $(CFLAGS) -c Pod.cpp

Server.o: Server.cpp Resource.hpp
	$(CC) $(CFLAGS) -c Server.cpp

KubernetesCluster.o: KubernetesCluster.cpp Server.hpp Pod.hpp
	$(CC) $(CFLAGS) -c KubernetesCluster.cpp

CloudExceptions.o: CloudExceptions.cpp 
	$(CC) $(CFLAGS) -c CloudExceptions.cpp

Cloud_Util.o: Cloud_Util.cpp Pod.hpp Container.hpp Server.hpp Resource.hpp KubernetesCluster.hpp CloudExceptions.hpp
	$(CC) $(CFLAGS) -c Cloud_Util.cpp

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
