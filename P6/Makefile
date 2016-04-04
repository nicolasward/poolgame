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



all:: testBoule

Vecteur.o: Vecteur.cc Vecteur.h 

Boule.o: Boule.cc Boule.h Vecteur.h Integrateur.h IntegrateurEuler.h

testBoule.o: testBoule.cc Boule.h Vecteur.h Integrateur.h IntegrateurEuler.h

Integrateur.o: Integrateur.cc Integrateur.h Boule.h 

IntegrateurEuler.o: IntegrateurEuler.cc IntegrateurEuler.h

testBoule: testBoule.o Boule.o Vecteur.o IntegrateurEuler.o Integrateur.o


clean:
		rm *.o
