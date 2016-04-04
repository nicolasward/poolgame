CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
CXXFLAGS += -g                    # pour debugger
#CXXFLAGS += -pg                   # pour profiler
#LDFLAGS  += -pg                   # pour profiler
#CXXFLAGS += -O2                   # pour optimiser la vitesse



all:: testChocs

Vecteur.o: Vecteur.cc Vecteur.h 

Boule.o: Boule.cc Boule.h Vecteur.h Integrateur.h IntegrateurEuler.h Objet.h Dessinable.h Support_a_dessin.h

testChocs.o: testChocs.cc Boule.h Vecteur.h Integrateur.h IntegrateurEuler.h

Integrateur.o: Integrateur.cc Integrateur.h Boule.h 

IntegrateurEuler.o: IntegrateurEuler.cc IntegrateurEuler.h

Systeme.o: Systeme.cc Systeme.h

testChocs: testChocs.o Boule.o Vecteur.o IntegrateurEuler.o Integrateur.o Systeme.o


clean:
	rm *.o
