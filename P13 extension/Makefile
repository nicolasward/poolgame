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



all:: testKutta

Vecteur.o: Vecteur.cc Vecteur.h 

Boule.o: Boule.cc Boule.h Vecteur.h Integrateur.h IntegrateurKutta.h

testKutta.o: testKutta.cc Boule.h Vecteur.h Integrateur.h IntegrateurKutta.h

Integrateur.o: Integrateur.cc Integrateur.h Boule.h 

IntegrateurKutta.o: IntegrateurKutta.cc IntegrateurKutta.h

testKutta: testKutta.o Boule.o Vecteur.o IntegrateurKutta.o Integrateur.o


clean:
		rm *.o
