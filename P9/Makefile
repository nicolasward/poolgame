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



all:: exerciceP9

Vecteur.o: Vecteur.cc Vecteur.h 

Boule.o: Boule.cc Boule.h Vecteur.h Integrateur.h IntegrateurEuler.h Objet.h Dessinable.h Support_a_dessin.h

exerciceP9.o: exerciceP9.cc Boule.h Vecteur.h Integrateur.h IntegrateurEuler.h 

Integrateur.o: Integrateur.cc Integrateur.h Boule.h 

IntegrateurEuler.o: IntegrateurEuler.cc IntegrateurEuler.h

Systeme.o: Systeme.cc Systeme.h

Objet.o: Objet.cc Objet.h Boule.h Vecteur.h

Dessinable.o: Dessinable.cc Dessinable.h Support_a_dessin.h

TextViewer.o: TextViewer.cc TextViewer.h

exerciceP9: exerciceP9.o Vecteur.o Boule.o Integrateur.o IntegrateurEuler.o Systeme.o Objet.o Dessinable.o TextViewer.o


clean:
	rm *.o
