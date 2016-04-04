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



all:: testNewmark

Vecteur.o: Vecteur.cc Vecteur.h 

Boule.o: Boule.cc Boule.h Vecteur.h Integrateur.h IntegrateurNewmark.h

testNewmark.o: testNewmark.cc Boule.h Vecteur.h Integrateur.h IntegrateurNewmark.h

Integrateur.o: Integrateur.cc Integrateur.h Boule.h 

IntegrateurNewmark.o: IntegrateurNewmark.cc IntegrateurNewMark.h

testNewmark: testNewmark.o Boule.o Vecteur.o IntegrateurNewmark.o Integrateur.o


clean:
		rm *.o
