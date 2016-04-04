#ifndef SYSTEME_H
#define SYSTEME_H

#include "Boule.h"
#include "Integrateur.h"
#include "Tapis.h"

class Systeme {

	public:
	
		// methodes pour ajouter des boules/objets
		void ajoute_boule(Boule*);
		void ajoute_objet(Objet*);
		
		void dessine();


		// evolution du Systeme
		void evolue(double dt);

		// constructeur
		Systeme(Integrateur* integrateur, double const& L, double const& l)
		: I(integrateur), T(L, l), P1(L, l), P2(L, l), P3(L, l), P4(L, l) {}

		// on empeche la copie de Systeme a cause des problemes lies aux pointeurs
		Systeme (const Systeme&) = delete ;

		// destructeur de notre Systeme 
		~Systeme();
		
		// affichage
		std::ostream& affiche(std::ostream&) const;
		
	private:
		Integrateur* I;
		std::vector<Boule*> boules;
		std::vector<Objet*> objets;
		Tapis T;
		Paroi P1, P2, P3, P4;
};

std::ostream& operator<< (std::ostream&, Systeme const& S);

#endif
