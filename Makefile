CPP=g++ --std=c++11

CFLAGS= -Wall

all : exe

exe : main.o Direction.o Conteneur.o Piece.o Objet.o Poison.o Armes.o Boucliers.o Personnage.o MotCleCommandes.o Medicaments.o Jeu.o Sorciere.o Moine.o Guerrier.o Amazone.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

Direction.o : Direction.cpp Direction.hpp
	$(CPP) $(CFLAGS) -c $<

Conteneur.o : Conteneur.cpp Conteneur.hpp
	$(CPP) $(CFLAGS) -c $<

Piece.o : Piece.cpp Piece.hpp
	$(CPP) $(CFLAGS) -c $<

Objet.o : Objet.cpp Objet.hpp
	$(CPP) $(CFLAGS) -c $<

Poison.o : Poison.cpp Poison.hpp
	$(CPP) $(CFLAGS) -c $<

Armes.o : Armes.cpp Armes.hpp
	$(CPP) $(CFLAGS) -c $<

Boucliers.o : Boucliers.cpp Boucliers.hpp
	$(CPP) $(CFLAGS) -c $<

Medicaments.o : Medicaments.cpp Medicaments.hpp
	$(CPP) $(CFLAGS) -c $<

MotCleCommandes.o : MotCleCommandes.cpp MotCleCommandes.hpp
	$(CPP) $(CFLAGS) -c $<

Personnage.o : Personnage.cpp Personnage.hpp
	$(CPP) $(CFLAGS) -c $<

Jeu.o : Jeu.cpp Jeu.hpp
	$(CPP) $(CFLAGS) -c $<

Amazone.o : Amazone.cpp Amazone.hpp
	$(CPP) $(CFLAGS) -c $<

Guerrier.o : Guerrier.cpp Guerrier.hpp
	$(CPP) $(CFLAGS) -c $<

Moine.o : Moine.cpp Moine.hpp
	$(CPP) $(CFLAGS) -c $<

Sorciere.o : Sorciere.cpp Sorciere.hpp
	$(CPP) $(CFLAGS) -c $<



clean :
	rm *.o exe
	
test: all
	./exe